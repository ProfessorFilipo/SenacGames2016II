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
	//scanf("%s", Nome);
	scanf("%[^\n]", Nome); // mascara para ler a linha inteira 
	                       // digitada pelo usuario, ignorando
	                       // os espacos em branco.
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

void MontaTabuleiro(char M[_Tab_H_][_Tab_W_], int Pontos, int Vidas, char* Nome)
{
	int i, j;

	// teste teste - enche tudo de pontos
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
	
    // penultima linha
	M[_Tab_H_-3][0]         = 219;
	M[_Tab_H_-3][1]         = 200;
    M[_Tab_H_-3][_Tab_W_-1] = 219;
	M[_Tab_H_-3][_Tab_W_-2] = 188;
	for(j=2; j<(_Tab_W_-2); j++) M[_Tab_H_-3][j] = 205;
	
	// ultima linha	
    for(j=0; j<(_Tab_W_); j++) M[_Tab_H_-2][j] = 219;
    
    // Barra de Informacoes
    M[_Tab_H_-1][0] = 245; //M[_Tab_H_-1][1] = ':'; M[_Tab_H_-1][2] = ':';
    M[_Tab_H_-1][1] = 'V'; 
	M[_Tab_H_-1][2] = 'I'; 
	M[_Tab_H_-1][3] = 'D'; 
	M[_Tab_H_-1][4] = 'A'; 
	M[_Tab_H_-1][5] = 'S'; 
	M[_Tab_H_-1][6] = ':';
	
	// imprime Vidas restantes
	for(j=0; j<5; j++) M[_Tab_H_-1][7+j] = 241; // preenche com cruzes
	for(j=0; j<Vidas; j++) // agora, preenche com as vidas correspondentes.
	{
		M[_Tab_H_-1][7+j] = 001;
	}
	
	// imprime pontos
	M[_Tab_H_-1][20] = 'P';
	M[_Tab_H_-1][21] = 'O';
	M[_Tab_H_-1][22] = 'N';
	M[_Tab_H_-1][23] = 'T';
	M[_Tab_H_-1][24] = 'O';
	M[_Tab_H_-1][25] = 'S';
	M[_Tab_H_-1][26] = ':';
	
	char pontos[7]; // 7 = quantidade maxima de digitos + um digito para terminador.
	sprintf( pontos,"%6d", Pontos); // o %6d garante o alinhamento do nro a direita.
	// sprintf "imprime" em 'pontos' a string correspondente ao valor de 'Pontos'.
	for(j=0; j<6; j++)
	   M[_Tab_H_-1][27+j] = pontos[j];

    // imprime nome do jogador
    for(j=0; j<50; j++)
    {
       if(Nome[j] == NULL)
	   {
	   	   break;
	   }   else M[_Tab_H_-1][35+j] = Nome[j];
	}
    /*for(j=0; j<50; j++)
    {
	   M[_Tab_H_-1][35+j] = Nome[j];
	}*/
       
}

void MostraTela( char M[_Tab_H_][_Tab_W_] )
{
    int i,j;
 
    //printf("\n");
	for(i=0; i<_Tab_H_; i++)
    {
        for(j=0; j<_Tab_W_; j++)
        {
            gotoxy(i,j);
            printf("%c", M[i][j]);
        }
        //printf("\n");
    }
}

int main(int argc, char *argv[]) {

    //char Nome[50];
    char *Nome = (char*)malloc( 50 * sizeof(char) );
    if(Nome == NULL)
    {
    	printf("\n>>> Erro alocando memória! \n");
    	return -1;
	}
    
    char Tabuleiro[_Tab_H_][_Tab_W_];

    system("mode 100, 120");
    TelaAbertura   (Nome);
    TelaInicioFase (1);
    MontaTabuleiro (Tabuleiro, 7777, 3, Nome);
    MostraTela     (Tabuleiro);
    
    //printf("\n %s\n ", Nome);
    
	return 0;
}
