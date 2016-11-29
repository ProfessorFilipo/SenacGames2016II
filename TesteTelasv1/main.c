#include <stdio.h>
#include <stdlib.h>

#define _LINHAS_  5
#define _COLUNAS_ 5

void AtualizaTabuleiro(int Tabuleiro[_LINHAS_][_COLUNAS_])
{
    /*
    ** Atualiza os valores no tabuleiro
    */
    int i,j,cont=0;
    for(i=0; i < _LINHAS_; i++)
    {
        for(j=0; j < _COLUNAS_; j++)
        {
            Tabuleiro[i][j] = cont++;
        }
    }
}

void AtualizaTela(int Tabuleiro[_LINHAS_][_COLUNAS_])
{
    /*
    ** Atualiza o tabuleiro na tela
    */
    int i,j;

    system("cls");
    for(i=0; i < _LINHAS_; i++)
    {
        for(j=0; j < _COLUNAS_; j++)
        {
            printf(" %3d ", Tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main()
{
   char tecla;
   int Tabuleiro[_LINHAS_][_COLUNAS_];

    while(1)
    {
        if(kbhit())
        {
            tecla = getch();
            switch(tecla)
            {
                case 'w': case 'W':
                    AtualizaTabuleiro(Tabuleiro);
                    AtualizaTela(Tabuleiro);
                     break;
                default:
                    printf("::: %c\n", tecla);
                     break;
            }
        }

    }

    return 0;
}
