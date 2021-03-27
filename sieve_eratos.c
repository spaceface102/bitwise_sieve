#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*each "new" bit represents a new number
therefore 1 byte is a 8 different numbers
if a bit is == 1, then its prime, otherwise
if bit is == 0 it is NOT prime.
We will be counting from least sig bit*/


int main(void)
{
	uint64_t maxnumber;
	printf("What is the max number you want to check for primes? ");
	scanf("%lu", &maxnumber); 
	if (maxnumber <= 1)
	{
		printf("Primes are ALWAYS greater than or equal to 2!\n");
		return 42; //error
	}

	/*If I was under space constraints I could use 32bit var for
	"checktill", the downside being that maxnumber could not be
	larger than 2^64 - 1 - 2(2^32 - 1), on side note figured this
	out by taking max representable number with 64 bits (unsigned
	of course) and subtracting that by the the max representable
	number with 32 bits squared aka: 2^64 - 1 - (2^32 - 1)^2 which 
	equals 2(2^32 - 1). But even though 2(2^32 - 1) is a huge number
	I could still represent 99.9999999534% of the numbers that 2^64 -1
	is able to cover. But I'm loaded with RAM so we chillin B) */
	uint64_t checktill = sqrt(maxnumber); 
	uint64_t arraysize = (maxnumber/64) + 1; //64 bits in 8 bytes
	uint64_t sievearray = malloc(arraysize*sizeof(uint64_t));
	uint64_t checknum = 2; //start with first prime
	uint64_t currnum; //counter

	//set all bytes to 0xff
	memset(sievearray, 0xff, arraysize*sizeof(uint64_t));
	/*make bit number 0 and bit number 1 NOT prime by setting them == 0*/
	sievearray[0] <<= 2;

	//look for primes
	while(checktill--)
	{	
		//check if current "checknum" is prime
		if ( sievearray[checknum>>6]&(1<<(checknum&63)) ) //acts as bit mask
			for(currnum = checknum+checknum; currnum < maxnumber; currnum += checknum)
				sievearray[currnum>>6] &= ~(1<<(currnum&63)); //>>6 == /64 && &63 == %64
		checknum++;
	}

	//check number of 1s, inorder to check number of primes
	uint64_t numberofprimes = 0;
	for(uint64_t i = 0; i < arraysize; i++)
		for(;sievearray[i]; sievearray[i] &= sievearray[i] - 1, numberofprimes++);

	printf("Number of primes: %lu\n", numberofprimes);
	free(sievearray);
	return 0;
}

