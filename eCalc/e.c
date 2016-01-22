#include "stdio.h"
#include <iostream>
#define DIGITS 10000
main()
{
	ofstream fout;
	unsigned A[DIGITS],leftCarry,i,j;
	printf("2.");
	for(i = 0;i<DIGITS;i++)
	{
		A[i] = 1;
	}
	for(i=0;i<(DIGITS-1);i++)
	{
		leftCarry = 0;
		for(j = 0; j<DIGITS; j++)
		{
			A[j]*=10;
		}
		for(j = DIGITS-1; j>0;j--)
		{//printf("hello");
			A[j]+=leftCarry;
			leftCarry = A[j]/(j+1);
			A[j] = A[j]%(j+1);
		}
		printf("%d",leftCarry);
	}

}




