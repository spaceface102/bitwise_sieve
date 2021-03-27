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

struct sieve{
	uint64_t maxnumber; //maxnumber to check as prime
	uint64_t *sievearray;
	uint64_t arraysize;
	uint64_t checknum;
	uint64_t arrayindex;
}


int getstatus(struct sieve *soe);
int setNOTprime(struct sieve *soe);

int main(void)
{
	struct sieve soe; //soe == sieve of eratosthenes
	uint64_t checktill;
	/*printf("What is the max number you want to check for primes? ");
	scanf("%lu", &soe.maxnumber); */
	if (soe.maxnumber <= 1)
	{
		printf("Primes are ALWAYS greater than or equal to 2!\n");
		return 42; //error
	}

	soe.maxnumber = 32;
	checktill = sqrt(soe.maxnumber);
	soe.arraysize = (soe.maxnumber/64) + 1; //64 bits in 8 bytes
	soe.sievearray = malloc(soe.arraysize*sizeof(uint64_t));
	soe.checknum = 2; //start with first prime
	uint64_t currnum; //counter

	//set all bytes to 0xff
	memset(soe.sievearray, 0xff, soe.arraysize*sizeof(uint64_t));
	/*start counting by 1, therefore least sig bit in sieve[0] represent # 1
	and since 1 is NOT prime, set least sigbit of sieve[0] to 0 */
	soe.sievearray[0] <<= 1;

	//look for primes
	while(checktill--)
	{	
		if (getstatus(sieve, currnumber))
		{
			for(currnumber = currnumber; number < maxnumber; number++)
			{
			//makeNOTprime
			}
		}
		currnumber++;
	}

	//check number of 1s, inorder to check number of primes
	free(sieve);
	return 0;
}

int getstatus(struct sieve *soe)
{		
}
