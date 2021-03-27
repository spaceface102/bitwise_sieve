#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*each "new" bit represents a new number
therefore 1 byte is a 8 different numbers
if a bit is == 0, then its prime, otherwise
if bit is == 1 it is NOT prime.
We will be counting from least sig bit*/
int main(void)
{
	uint64_t maxnumber = 32;
	/*printf("What is the max number you want to check for primes? ?");
	scanf("%lu", &maxnumber); */
	uint64_t arraysize = (maxnumber/64) + 1;
	uint64_t *sieve = malloc(arraysize*sizeof(uint64_t));
	uint64_t checktill = sqrt(maxnumber);
	//check number of 1s, inorder to check number of primes
	free(sieve);
}
