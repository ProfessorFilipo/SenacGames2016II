#include <stdio.h>
#include <stdlib.h>

#define _ALTURA_  30
#define _LARGURA_ 30


void CarregaArquivo(char Tab[_ALTURA_][_LARGURA_], char* NomeArquivo)
{
	FILE* arq = NULL;
	char Linha[1024];
	int i=0, j=0, cont=0, ColCont=0, LinCont=0;
	
	arq = fopen(NomeArquivo, "r");
	if(arq == NULL)
	{
		printf("\n::: Erro abrindo arquivo %s ! \n", NomeArquivo);
		exit;
	}
	
	while( fgets(Linha, 1024, arq) != NULL)
	{
		// deve ignorar a primeira linha!
		if(LinCont==0) 
		{
			LinCont++;
			continue;	
		}
		
		
		
		
		
		
		
		
		
		LinCont++;
		
	}
	
	
}


int main(int argc, char *argv[]) {
	return 0;
}
