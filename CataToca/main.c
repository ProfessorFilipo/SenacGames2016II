#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


#define _Tab_H_ 20
#define _Tab_W_ 79

int RandI(int minVal, int maxVal)
{
    return (double)rand()/RAND_MAX * (maxVal - minVal) + minVal;
}
 
//Defines gotoxy() for ANSI C compilers.
void gotoxy(short x, short y) {
COORD pos = {y, x};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void TelaAbertura(char *Nome)
{
	system("cls");
	printf("########################################################\n");
	printf("########################################################\n");
	printf("######  +---- +---+ ----- +---+  T        %c%c%c%c%c%c%c#######\n", 201, 205, 205, 205, 205, 187, ' ');
	printf("######  |     |   |   |   |   |    O      %c%c%c%c%c%c%c#######\n", 186, 001, 001, 001, 001, 186, ' ');
	printf("######  |     |---|   |   |---|      C    %c%c%c%c%c%c%c#######\n", 186, 001, 001, 001, 001, 186, ' ');
	printf("######  +---- |   |   |   |   |        A  %c%c%c%c%c%c%c#######\n", 200, 205, 205, 205, 205, 188, ' ');
	printf("########################################################\n");
	printf("########################################################\n");
	printf("     U M   J O G O   D E   I N T E L I G E N C I A      \n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf(" Digite seu nome: ");
	scanf("%s", Nome);
}

void TelaInicioFase(int NroFase)
{
	int i=0;
	system("cls");
	printf("%c", 201);
	for(i=0; i<50; i++) printf("%c", 205);
	printf("%c",187);
	printf("\n%c                                                  %c", 186, 186);
	printf("\n%c                                                  %c", 186, 186);
	printf("\n%c                                                  %c", 186, 186);
	printf("\n%c                                                  %c", 186, 186);
	printf("\n%c                                                  %c", 186, 186);
	printf("\n%c               F    A    S    E                   %c", 186, 186);
	printf("\n%c                                                  %c", 186, 186);
	printf("\n%c                       %d                          %c", 186, NroFase, 186);
	printf("\n%c                                                  %c", 186, 186);
	printf("\n%c                                                  %c", 186, 186);
	printf("\n%c                                                  %c", 186, 186);
	printf("\n%c                                                  %c", 186, 186);
	printf("\n%c                                                  %c", 186, 186);
	printf("\n%c", 200);
	for(i=0; i<50; i++) printf("%c", 205);
	printf("%c", 188);
	printf("\n\n::: Pressione qualquer tecla para iniciar...");
	getch();
}

void MontaTabuleiro(char M[_Tab_H_][_Tab_W_] /*, int Acertos, int Erros, int Vidas*/)
{
	int i, j;

	for(i=0; i < _Tab_H_; i++)
	{
		for(j=0; j < _Tab_W_; j++)
		{
			M[i][j] = '.';
		}
	}

	
	
	// primeira linha
	for(j=0; j<(_Tab_W_); j++) M[0][j] = 219;
	
	// segunda linha
	M[1][0]         = 219;
	M[1][1]         = 201;
    M[1][_Tab_W_-1] = 219;
	M[1][_Tab_W_-2] = 187;
	for(j=2; j<(_Tab_W_-2); j++) M[1][j] = 205;
	
	// centro
	for(i=2; i<(_Tab_H_-2); i++)
	{
		M[i][0]         = 219;
		M[i][1]         = 186;
		M[i][_Tab_W_-1] = 219;
		M[i][_Tab_W_-2] = 186;
		for(j=2; j<(_Tab_W_-2); j++)
		{
			M[i][j] = ' ';
		}
	}
	
	

}

void MostraTela( char M[_Tab_H_][_Tab_W_] )
{
    int i,j;
 
    for(i=0; i<_Tab_H_; i++)
    {
        for(j=0; j<_Tab_W_; j++)
        {
            gotoxy(i,j);
            printf("%c", M[i][j]);
        }
    }
}

int main(int argc, char *argv[]) {

    char Nome[50];
    char Tabuleiro[_Tab_H_][_Tab_W_];

    //TelaAbertura   (&Nome);
    //TelaInicioFase (1);
    MontaTabuleiro (Tabuleiro);
    MostraTela     (Tabuleiro);
    
    //printf("\n %s\n ", Nome);
    
	return 0;
}
