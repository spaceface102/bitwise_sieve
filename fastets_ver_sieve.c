#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	uint64_t maxnumber = 1000000000; //1e9 used for testing, will be overwritten
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
	uint64_t checknum = 7; //starting at 4th prime 
	uint64_t currnum;


/*
	Made this a further optimization
	Skip turning all the multiples of 3 into
	not prime by filling with initial patter first!
	I as well skip all the multiples of 2, but this is
	now adds mults of 3
*/

/*
	//taking care of 1st and 2nd prime (2 & 3)
	sievearray[0] = 0x28a28a28a28a28ac;
	if (arraysize > 1) sievearray[1] = 0xa28a28a28a28a28a;
	if (arraysize > 2) sievearray[2] = 0x8a28a28a28a28a28;
	if (arraysize > 3) sievearray[3] = 0x28a28a28a28a28a2;
	for(uint64_t i = 4, j = 1; i < arraysize; i++, j++)
		sievearray[i] = sievearray[j];
*/


//after this, dimenishing returns
/*
	//memory analysis when have cleared mults of 2, 3, and 5
	0x7fffffffdfc0: 0x28228a20a08a28ac      0x828228a20a08a288
	0x7fffffffdfd0: 0x8828228a20a08a28      0x28828228a20a08a2
	0x7fffffffdfe0: 0xa28828228a20a08a      0x8a28828228a20a08
	0x7fffffffdff0: 0x08a28828228a20a0      0xa08a28828228a20a
	0x7fffffffe000: 0x0a08a28828228a20      0x20a08a28828228a2
	0x7fffffffe010: 0xa20a08a28828228a      0x8a20a08a28828228
	0x7fffffffe020: 0x28a20a08a2882822      0x228a20a08a288282
	0x7fffffffe030: 0x8228a20a08a28828      0x28228a20a08a2882
	0x7fffffffe040: 0x828228a20a08a288      0x8828228a20a08a28
	0x7fffffffe050: 0x28828228a20a08a2      0xa28828228a20a08a
	0x7fffffffe060: 0x8a28828228a20a08      0x08a28828228a20a0
	0x7fffffffe070: 0xa08a28828228a20a      0x0a08a28828228a20
	0x7fffffffe080: 0x20a08a28828228a2      0xa20a08a28828228a
	0x7fffffffe090: 0x8a20a08a28828228      0x28a20a08a2882822
	0x7fffffffe0a0: 0x228a20a08a288282      0x8228a20a08a28828
	0x7fffffffe0b0: 0x28228a20a08a2882      0x828228a20a08a288
*/

	//taking care of 1st, 2nd, and 3rd prime (2, 3, & 5)
	sievearray[0] = 0x28228a20a08a28ac;
	//do all the if check in order to ensure not accesing mem not supposed to
	if (arraysize > 1) sievearray[1] = 0x828228a20a08a288;
	if (arraysize > 2) sievearray[2] = 0x8828228a20a08a28;  
	if (arraysize > 3) sievearray[3] = 0x28828228a20a08a2;  
	if (arraysize > 4) sievearray[4] = 0xa28828228a20a08a;  
	if (arraysize > 5) sievearray[5] = 0x8a28828228a20a08;  
	if (arraysize > 6) sievearray[6] = 0x8a28828228a20a0;   
	if (arraysize > 7) sievearray[7] = 0xa08a28828228a20a;  
	if (arraysize > 8) sievearray[8] = 0xa08a28828228a20;   
	if (arraysize > 9) sievearray[9] = 0x20a08a28828228a2;  
	if (arraysize > 10) sievearray[10] = 0xa20a08a28828228a;
	if (arraysize > 11) sievearray[11] = 0x8a20a08a28828228;
	if (arraysize > 12) sievearray[12] = 0x28a20a08a2882822;
	if (arraysize > 13) sievearray[13] = 0x228a20a08a288282;
	if (arraysize > 14) sievearray[14] = 0x8228a20a08a28828;
	if (arraysize > 15) sievearray[15] = 0x28228a20a08a2882;
	for(uint64_t i = 16, j = 1; i < arraysize; i++, j++)
		sievearray[i] = sievearray[j];

	while(checknum <= checktill)
	{	
		if ( sievearray[checknum>>6]&(1UL<<(checknum&63)) )
			for(currnum = checknum*2; currnum <= maxnumber; currnum += checknum)
				sievearray[currnum>>6] &= ~(1UL<<(currnum&63)); 
		checknum += 2; //skip all even numbers
	}

	sievearray[arraysize - 1] &= (~0UL)>>(63 - (maxnumber&63));
	uint64_t numberofprimes = 0;
	for(uint64_t i = 0; i < arraysize; i++)
		for(;sievearray[i]; sievearray[i] &= sievearray[i] - 1, numberofprimes++);
	
	printf("Number of primes: %lu\n", numberofprimes);
	free(sievearray);
	return 0;
}
