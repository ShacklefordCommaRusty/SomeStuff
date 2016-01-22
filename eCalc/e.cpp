#include "stdio.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;
#define DIGITS 500000
int main()
{
	ofstream fout("500000.txt");
	short A[DIGITS],leftCarry;
		int i,j,k;

	for(k = 0; k < DIGITS; k++)
    {
		A[k] = 1;
    }
	fout << "e = 2. \n";
	//printf("e = 2. \n");
	for(i=0;i<(DIGITS-1);i++)
	{
		leftCarry = 0;
		for(j = 0; j<DIGITS; j++)
		{
			A[j] *= 10;
			//printf("A[%d] = %d\n", j, A[j] );
			//usleep(3000000);
		}
		for(j = DIGITS - 1; j > 0; j--)
		{
			A[j] += leftCarry;
			//printf("A[%d] = %d\n", j, A[j]);
			//usleep(3000000);
			leftCarry = A[j]/(j+1);
			//printf("leftCarry = %d\n", leftCarry);
			//usleep(3000000);
			A[j] = A[j]%(j+1);
			//printf("A[%d] = %d\n",j,A[j]);
			//usleep(3000000);
		}

		//printf("%d", leftCarry);
		fout << leftCarry;

		//std::cout.flush();
		if((i+1)%10 == 0)
		{
			fout << " ";
			//printf(" ");
		}
		if((i+1)%101 == 0)
		{
			fout << "\n";
			printf("\rCalculating: %.4f%% of %d digits", 100*((float)i/(float)DIGITS), DIGITS);
			std::cout.flush();
		}
	}
	printf("\rCalculating: 100.0000%% of %d digits\n", DIGITS);
	return 0;
}
