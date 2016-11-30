#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void Fibonacci(int N)
{
	/*
	** Mostra os N primeiros numeros
	* da sequencia de Fibonacci
	*/
	int aux, a, b, i;
	aux = 0;
	a   = 1;
	b   = 0;
	
	for(i=0; i<N; i++)
	{
		aux = a + b;
		a   = b;
		b   = aux;
		printf("%3d ::: %5d\n", i+1, aux);
	}
	
}

int main(int argc, char *argv[]) {
	
	Fibonacci(50);
	return 0;
}








