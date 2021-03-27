#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

/*each "new" bit represents a new number
therefore 1 byte is a 8 different numbers
if a bit is == 1, then its prime, otherwise
if bit is == 0 it is NOT prime.*/
int main(void)
{
	uint64_t maxnumber;
	printf("What is the max number you want to check for primes? ?");
	scanf("%lu", &maxnumber);

	uint64_t *sieve = calloc( (maxnumber/64) + 1, sizeof(uint64_t) );
	uint64_t checktill = sqrt(maxnumber);
	uint64_t currnum = 3;
	while(checktill--)
	{
		
	}
	

	//check number of 1s, inorder to check number of primes
	free(sieve);
}
