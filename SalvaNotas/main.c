#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(int argc, char *argv[]) 
{

  char Nome[50];
  char Notas[3];
  char resp     = NULL;
  int  cont     = 0;
  bool Continua = true;
  FILE* arq     = NULL;
  
  arq = fopen("notas.csv", "a");
  if (arq == NULL)
  {
  	printf("\nErro gerando arquivo! :-( \n");
  	return -1;
  }

  while(Continua)
  {
  	printf("\n\nInforme o primeiro nome do aluno %d:", ++cont);
  	scanf("%s", &Nome);
  	printf("\n informe as 3 notas correspondentes: ");
  	scanf("%d %d %d", &Notas[0], &Notas[1], &Notas[2]);
  	printf("\n ::: Dados informados: %s \t %d \t %d \t %d.", Nome, Notas[0], Notas[1], Notas[2]);
  	
  	// grava dados do aluno no arquivo
  	fprintf(arq, "%s; %d; %d; %d \n", Nome, Notas[0], Notas[1], Notas[2]);
  	
  	printf("\n ::: Deseja incluir mais um aluno [S/N]?");
  	resp = getch();
  	if(resp=='N' || resp=='n')
  	{
  		Continua = false;
	}
  }

   fclose(arq);
	return 0;
}
