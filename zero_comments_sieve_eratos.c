#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXNUMBER 1000000000
int main(void)
{
	uint64_t checktill = sqrt(MAXNUMBER); 
	uint64_t arraysize = (MAXNUMBER>>6) + 1; 
	uint64_t *sievearray = malloc(arraysize<<3); 
	uint64_t checknum = 3; 
	uint64_t currnum;

	memset(sievearray, 0xaa, arraysize<<3);
	sievearray[0] = 0xaaaaaaaaaaaaaaac; 
	
	while(checknum <= checktill)
	{	
		if ( sievearray[checknum>>6]&(1UL<<(checknum&63)) )
			for(currnum = checknum*2; currnum <= MAXNUMBER; currnum += checknum)
				sievearray[currnum>>6] &= ~(1UL<<(currnum&63)); 
		checknum++;
	}

	sievearray[arraysize - 1] &= (~0UL)>>(63 - (MAXNUMBER&63));
	uint64_t numberofprimes = 0;
	for(uint64_t i = 0; i < arraysize; i++)
		for(;sievearray[i]; sievearray[i] &= sievearray[i] - 1, numberofprimes++);
	
	printf("Number of primes: %lu\n", numberofprimes);
	free(sievearray);
	return 0;
}
