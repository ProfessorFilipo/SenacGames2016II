#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool EhPrimo(int nro)
{
	/* retorna TRUE se valor informado 
	** representar um nro primo.
	*/
	bool dividiu = false;
	int i;
	
	for(i=2; i<nro; i++)
	{
		if(nro % i == 0) dividiu = true;
	}
	
	return !dividiu;
}

void MostraPrimos(int quantidade)
{
	int cont=0, nro=1;
	while (cont<quantidade)
	{
		if(EhPrimo(nro))
		{
			printf("%3d: %3d\n", cont, nro);
			cont++;
		}
		nro++;
	}
	
}

int main(int argc, char *argv[]) {
	
	system("cls");
	printf("\n\n::: MOSTRA OS 100 PRIMEIROS NROS PRIMOS :::\n\n");
	
	MostraPrimos(500);
	
	return 0;
	
	int x;
	system("cls");
	printf("\n Informe um valor: ");
	scanf("%d", &x);
	if(EhPrimo(x))
	{
		printf("\nO número %d é primo!\n", x);
	}
	else
	{
		printf("\nO número %d NAO É primo!\n", x);
	}
	
	
	return 0;
}
