#include <stdio.h>
#include <stdlib.h>

#define _LIN_ 10
#define _COL_ 10

void LimpaMatriz(int M[_LIN_][_COL_])
{
	int i, j;
	for(i=0; i<_LIN_; i++)
	{
		for(j=0; j<_COL_; j++)
		{
			M[i][j] = 1;
		}
	}
	
}

void MostraMatriz(int M[_LIN_][_COL_])
{
	//system("cls");
	
	int i, j;
	for(i=0; i<_LIN_; i++)
	{
		for(j=0; j<_COL_; j++)
		{
			printf(" %2d ", M[i][j]);
		}
		printf("\n");
	}
}


int main(int argc, char *argv[]) {
	
	int Tab[_LIN_][_COL_];
	
	MostraMatriz(Tab);
	LimpaMatriz(Tab);
	MostraMatriz(Tab);
	
	return 0;
}
