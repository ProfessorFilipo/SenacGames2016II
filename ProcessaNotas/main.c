#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) 
{

  char  Nome[50];
  char  Linha[1024];
  int   Notas[3];
  float media = 0.0;
  FILE* arq   = NULL;
  int i;
  
  // abre arquivo contendo as notas
  arq = fopen("W:\\Filipo\\Projetos\\SalvaNotas\\notas.csv", "r");
  if( arq == NULL )
  {
  	printf("\nErro abrindo arquivo de notas! :-( \n");
  	return -1;
  }
  
  while( fgets(Linha, 1024, arq))
  {
  	  printf("Linha lida: '%s'\n", Linha);
  	  // tenta ler o nome
  	  int pos=0;
  	  for(i=0; i<50; i++) Nome[i] = ' ';
	  while(Linha[pos] != ';')
  	  {
  	    Nome[pos] = Linha[pos];
  	    pos++;
	  }
  	  printf("O nome lido foi %s\n", Nome);
  	  
  }

  fclose(arq);

	return 0;
}
