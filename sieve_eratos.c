#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
	uint64_t numbits;
	printf("How many bits do you want?");
	scanf("%lu", &numbits);
	uint64_t *seive = calloc( (numbits/64) + 1, sizeof(uint64_t) );

	free(seive);
}
