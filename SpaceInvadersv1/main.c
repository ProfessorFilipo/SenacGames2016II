#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define _Cenario_W_ 79 // largura do cenario
#define _Cenario_H_ 20 // altura do cenario
#define _Nave_W_     5 // largura da nave
#define _Nave_H_     3 // altura da nave

int SorteiaInteiro(int Minimo, int Maximo)
{
	return rand() % (Maximo - Minimo + 1) + Minimo;
}


void Terreno(char M[_Cenario_H_][_Cenario_W_], int PosHorizonte)
{
	
	// teste - preench com zeros
	int i, j;
	for(i=PosHorizonte; i < _Cenario_H_; i++)
	{
		for(j=0; j < _Cenario_W_; j++)
		{
			M[i][j] = '_';
		}
	}
	
	
	
	/*
    // obtem um ponteiro para a janela de console 
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int i = 0;

    // percorre a escala de cores 
    for(; i < 255; i++)
    { 
        SetConsoleTextAttribute(hConsole, i);
        printf("#");
    }
    */
  	
}

void Estrelas(char M[_Cenario_H_][_Cenario_W_], int PosHorizonte, int quantEstrelas)
{
	/*
	** popula o Cenario com estrelas em posicoes aleatorias
	** na quantidade indicada por parametro e sempre
	** acima da linha do horizonte.
	*/
	int i, linha, coluna;
	for(i=0; i < quantEstrelas; i++)
	{
		linha  = SorteiaInteiro(0, PosHorizonte-1);
		coluna = SorteiaInteiro(0, _Cenario_W_);
		M[linha][coluna] = '.';
	}
	
	
}

void LimpaTela(char M[_Cenario_H_][_Cenario_W_])
{
	int i,j;
	for(i=0; i<_Cenario_H_; i++)
	{
		for(j=0; j<_Cenario_W_; j++)
		{
			M[i][j] = ' ';
		}
	}
	
}

void MostraTela(char M[_Cenario_H_][_Cenario_W_])
{
	system("cls");
	int i,j;
	for(i=0; i<_Cenario_H_; i++)
	{
		for(j=0; j<_Cenario_W_; j++)
		{
			printf("%c", M[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]) {
	
	char Cenario[_Cenario_H_][_Cenario_W_];
	srand(time(NULL));
	
	char Nave[_Nave_H_][_Nave_W_] = {
	                                 {' ',' ','^',' ',' ',},
	                                 {' ','[','@',']',' '},
									 {'#','#','#','#','#'}
									};
	
	LimpaTela (Cenario);
    Estrelas  (Cenario, 15, 10)	;
	Terreno   (Cenario, 15);
	MostraTela(Cenario);
	
	int i,j;
	for(i=0; i<_Nave_H_; i++)	
	{
		for(j=0; j<_Nave_W_; j++)
		{
			printf("%c", Nave[i][j]);
		}
		printf("\n");
	}
	// teste
	//int i, x;
	//for(i=0; i < 20; i++)
	//   printf(" %d - ", SorteiaInteiro(0,_Cenario_W_));
	
	return 0;
}
