#include <stdio.h>
#include <stdlib.h>

#define _LARGURA_ 30
#define _ALTURA_  20

void MostraTabuleiro(char Tab[_ALTURA_][_LARGURA_])
{
	int i, j;
	
	system("cls");
	
	for(i=0; i<_ALTURA_; i++)
	{
		for(j=0; j<_LARGURA_; j++)
		{
			printf("%c", Tab[i][j]);
		}
		printf("\n");
	}
	
}


void LimpaTabuleiro(char Tab[_ALTURA_][_LARGURA_], int ASCIICode)
{
	//
	// Preenche o tabuleiro com o caracter informado em ASCIICode
	//	
	int i, j;
	
	for(i=0; i<_ALTURA_; i++)
	{
		for(j=0; j<_LARGURA_; j++)
		{
			Tab[i][j] = ASCIICode;
		}
	}
}

void CarregaTabuleiro(char Tab[_ALTURA_][_LARGURA_], char* NomeArquivo)
{
	//
	// lê as informações no arquivo e atualiza o tabuleiro.
	// o formato do arquivo prevê uma posição do tabuleiro
	// por linha, no formato "%d %d %d", sendo, da esquerda
	// paraa direita: posicao X (altura), posição Y (largura)
	// e código ASCII do caracter correspondente. linhas cujo
	// primeiro caracter for igual a '#' devem ser ignoradas.
	// O objetivo eh permitir que o usuário utilize comentários.
	//
	FILE* arq = NULL;
	char Linha[1024];
	int PosX, PosY, ASCIICode;
	
	arq = fopen(NomeArquivo, "r");
	if(arq == NULL)
	{
		printf("\n:::Erro abrindo arquivo %s !!!\n", NomeArquivo);
		return -1;
	}
	
	while( fgets(Linha, 1024, arq) != NULL)
	{
		// Linha é comentario?
		if(Linha[0] == '#')
		{
			printf("Ignorando a linha: %s \n", Linha);
		}
		else
		{
			printf("Linha lida: %s \n", Linha);	
			// faz o parsing dos valores contidos na linha
			int pos=0, aux=0;
			char Buffer[1024];
			memset(Buffer, 0, 1024);
			while(Linha[pos] != ' ')
			{
				Buffer[aux] = Linha[pos];
				pos++;
				aux++;
			}
			PosX = atoi(Buffer);

			pos++;
			aux=0;
			memset(Buffer, 0, 1024);
			while(Linha[pos] != ' ')
			{
				Buffer[aux] = Linha[pos];
				pos++;
				aux++;
			}
			PosY = atoi(Buffer);

			pos++;
			aux=0;
			memset(Buffer, 0, 1024);
			while(Linha[pos] != '\n')
			{
				Buffer[aux] = Linha[pos];
				pos++;
				aux++;
			}
			ASCIICode = atoi(Buffer);
			
			Tab[PosX][PosY] = ASCIICode;
			printf("PosX: %d - PosY: %d Caracter: %c \n", PosX, PosY, ASCIICode);
		}
		
		memset(Linha, 0, 1024); // limpa a Linha!
		//for(i=0; i<1024; i++) Linha[i] = 0;
		
		// teste teste
		/*int i,j;
		for(i=0; i<_ALTURA_; i++)
		{
			for(j=0; j<_LARGURA_; j++)
			{
				printf("%c", Tab[i][j]);
			}
			printf("\n");
		} */
	}
	fclose(arq);
}

int main(int argc, char *argv[]) {
	
	char Tabuleiro[_ALTURA_][_LARGURA_];
	
	LimpaTabuleiro  (Tabuleiro, 0);
	CarregaTabuleiro(Tabuleiro, "W:\\Filipo\\Projetos\\DOSEngine\\fase1.map");
	MostraTabuleiro (Tabuleiro);
	
	
	
	
	return 0;
}
