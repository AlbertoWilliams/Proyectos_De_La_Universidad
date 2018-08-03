/*
Ejercicio 3:

Realizar un programa que permita calcular el valor de la serie 
hasta que el termino calculado converja al valor de 0.000001:

S = 1 + (x-1)/1! + x^2-2/2! + x^3-3/3! + ... + x^n-n/n!
*/

#include <stdlib.h>
#include  <stdio.h>

int main(int argc, char* argv[])
{
	int user_value;

	long serie_value = 1.0L;
	long objective = 0.000001L;
	int factorial = 1; 
	int iterator = 1;

	printf("Ingrese un valor para x: ");
	scanf("%d", &user_value);
	printf("Loading...\n");

	do
	{
		for(int i = 1; i <= iterator; i++)
		{
		    factorial = factorial * i;
		    printf("El factorial en la iteracion[%d] es: %ld\n", iterator, factorial);
		}

		int temporal_iterator = iterator;
		long temporal_user_value = user_value;
		
		int temporal_power_result = 1;
		
		while(temporal_iterator != 0)
		{
			temporal_power_result *= temporal_user_value;
			--temporal_iterator;
		}

		serie_value += (temporal_power_result - iterator) / factorial;
		iterator++;

		printf("%.6ld\n", serie_value);
		printf("%ld\n", iterator);
	} while(serie_value > objective);

	// El usuario ingresa su entrada

	return 0;
}
