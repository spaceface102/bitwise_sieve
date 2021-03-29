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
	uint64_t arraysize = (maxnumber>>6) + 1; //64 bits in 8 bytes
	//== arraysize*sizeof(uint64_t) since #<<3 == #*8 and sizeof(uint64_t) == 8    
	uint64_t *sievearray = malloc(arraysize<<3); 
	uint64_t checknum = 3; //start with second prime
	uint64_t currnum; //counter

	//set memory value so every multiple of multiple of 2 is auto NOT prime
	memset(sievearray, 0xaa, arraysize<<3);

	/*make bit number 0 and bit number 1 NOT prime by setting them == 0
	as well as keeping bit number 2 prime and any multiple of of 2 not prime*/
	sievearray[0] = 0xaaaaaaaaaaaaaaac; //a == 1010 aka 0(meaning NOT prime) every mult of 2
	/*c == 1100 since bit 0 and bit 1 not prime and bit 2 is prime only exception to the
	"0 every 2 mult" rule. 0xac == 1010 1100 (start counting from right to left)*/
	
	//look for primes
	while(checknum <= checktill) //inclusive range
	{	//NOTE: #>>6 == #/64 and &63 == %64

		//check if current "checknum" is prime
		/*checknum>>6 divides checknum by 64 and is used to access the correct array
		"&(1<<(checknum&63))" is the bit mask part where it will "bitwise and" the value
		of the correct index of the sieverarray by 1 with checknum&63 lagging 0's 
		(of course in base 2, binary) which will give me the value of the (checknum&63) + 1
		bit in the current array, either 0 or 1. If bit == 1 then it is prime, if bit == 0 it 
		is NOT prime and you should just skip the following processing*/
		if ( sievearray[checknum>>6]&(1UL<<(checknum&63)) ) //acts as bit mask
			//currnum = checknum*2 in order to ensure current prime stays prime (skipping checknum)
			for(currnum = checknum*2; currnum <= maxnumber; currnum += checknum)
				/*"~(1<<(currnum&63))" == all 1's except in bit position (currnum&63) + 1*/
				sievearray[currnum>>6] &= ~(1UL<<(currnum&63)); //>>6 == /64 && &63 == %64
		checknum += 2; //skip all the even numbers since they are sure to be not PRIME
	}

	/*make sure to not count extra bits as prime that are outside of maxnumber range
	need to do this since at minium every array index has 64 numbers due to having 64 bits*/
	sievearray[arraysize - 1] &= (~0UL)>>(63 - (maxnumber&63));


	//check number of 1s, inorder to check number of primes
	uint64_t numberofprimes = 0;
	for(uint64_t i = 0; i < arraysize; i++)
		for(;sievearray[i]; sievearray[i] &= sievearray[i] - 1, numberofprimes++);

	printf("Number of primes: %lu\n", numberofprimes);

/*
	//which primes
	uint64_t primenumber = 0;
	for(uint64_t i = 0; i < arraysize; i++)
		for(uint64_t j = 0; j < 64; j++, primenumber++)
			if (sievearray[i]&(1UL<<j))
				printf("%lu\n", primenumber);
*/
	free(sievearray);
	return 0;
}
