#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

	uint64_t checktill = sqrt(maxnumber); 
	uint64_t arraysize = (maxnumber>>6) + 1; 
	uint64_t *sievearray = malloc(arraysize<<3); 
	uint64_t checknum = 3; //starting at 2nd prime 
	uint64_t currnum;

	memset(sievearray, 0xaa, arraysize<<3);
	sievearray[0] = 0xaaaaaaaaaaaaaaac; 

	while(checknum <= checktill)
	{	
		if ( sievearray[checknum>>6]&(1UL<<(checknum&63)) )
			for(currnum = checknum*2; currnum <= maxnumber; currnum += checknum)
				sievearray[currnum>>6] &= ~(1UL<<(currnum&63)); 
		checknum++;
	}

	sievearray[arraysize - 1] &= (~0UL)>>(63 - (maxnumber&63));
	uint64_t numberofprimes = 0;
	for(uint64_t i = 0; i < arraysize; i++)
		for(;sievearray[i]; sievearray[i] &= sievearray[i] - 1, numberofprimes++);
	
	printf("Number of primes: %lu\n", numberofprimes);
	free(sievearray);
	return 0;
}
