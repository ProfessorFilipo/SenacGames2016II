#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 10

int main(int argc, char *argv[]) {

  int M[N][N];
  int i, j, cont, linha, coluna, aux;
  char hit, lasthit;
  
  cont = 1; aux = 0; linha = 0; coluna = 0;
  hit = lasthit = ' ';
  
  while(1)
  {

	if(kbhit()) 	{
		hit = getch();
	}
	switch(hit)
	{
		case 's': case 'S': case 'P': linha++;  break; // pra baixo
		case 'w': case 'W': case 'H': linha--;  break; // pra cima
		case 'd': case 'D': case 'M': coluna++; break; // pra direita
		case 'a': case 'A': case 'K': coluna--; break; // pra esquerda
		case 'o': case 'O': M[linha][coluna] = 10; break;     // poe ovo
	}
	
	// evita que a galinha saia do cercado!
	if(linha < 0)   linha  = 0;
	if(linha >= N)  linha  = N-1;
	if(coluna < 0)  coluna = 0;

	// janela de teletransporte direita!
	if(coluna >=N)
	{
		if((linha >= 5) && (linha <= 8))
		{
			coluna = 0;
		}
		else coluna = N-1;
	}
	
	// armazena o ultimo comando dado pelo usuario
	// para que este possa ser mostrado no painel.
	if(lasthit != hit && hit != ' ') lasthit = hit;
	hit = ' ';
	 	
  	for(i=0; i<N; i++)
  	{
  		for(j=0; j<N; j++)
  		{
  			if(M[i][j] != 10)
			   M[i][j] = 0;
		}
	} 
	if(M[linha][coluna]!=10)
	   M[linha][coluna] = 1;
  	
  	// mostra na tela
  	system("cls");
  	printf("\n N=%d ::: linha=%3d ::: coluna =%3d ::: hit='%c'\n\n", N, linha, coluna, lasthit);
  	for(i=0;i<N;i++) printf("___"); printf("\n");
	for(i=0; i<N; i++)
  	{
  		for(j=0; j<N; j++)	
  		{
  			switch(M[i][j])
  			{
  				case 1 : printf( " A "); break;
				case 10: printf( " * "); break;
  				default: printf( "   "); break;
			}
		}
		printf("\n");
	}
	for(i=0;i<N;i++) printf("___");
  }
  	
	return 0;
}
