#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	uint64_t arraysize = 200;
	uint64_t MAXNUMBER = (64*arraysize) - 1;
	uint64_t *sievearray = malloc(arraysize<<3); 
	uint64_t checknum; 
	uint64_t currnum;
	
	//checknum = 2;
	memset(sievearray, 0xaa, arraysize<<3);
	sievearray[0] = 0xaaaaaaaaaaaaaaac; 
	
	checknum = 3;
	for(currnum = checknum*2; currnum <= MAXNUMBER; currnum += checknum)
		sievearray[currnum>>6] &= ~(1UL<<(currnum&63)); 

	checknum = 5;
	for(currnum = checknum*2; currnum <= MAXNUMBER; currnum += checknum)
		sievearray[currnum>>6] &= ~(1UL<<(currnum&63)); 

	checknum = 7;
	for(currnum = checknum*2; currnum <= MAXNUMBER; currnum += checknum)
		sievearray[currnum>>6] &= ~(1UL<<(currnum&63)); 
	
	free(sievearray);
	return 0;
}
