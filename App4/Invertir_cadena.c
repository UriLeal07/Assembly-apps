/******************************************************
* Programador: Uri Leal                          
* Construido en C bajo la IDE Dev-C++ v5.7.1     
* "Programa que invierte el orden de los caracteres
*  que conforman a una cadena"  
* Benemerita Universidad Autonoma de Puebla    
******************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 150

main(void)
{
	char string[MAX], aux[MAX] = "", aux1;
	int i, j, n;
	
	printf("Ingresa una cadena: ");
	fgets(string,sizeof(string),stdin);
	
	printf("\n");
	puts(string);
	
	n = strlen(string);
	
	printf("\nEl tamano es %d\n", n);
	
	i = 0;
	j = n-1;
	
	while(j >= 0)
	{
		aux[i] = string[j];
		i++;
		j--;
	}
	
	i = 0;
	j = n-1;
	
	
	n/=2;
	
	while(i < n)
	{
		aux1 = string[i];
		string[i] = string[j];
		string[j] = aux1;
		i++;
		j--;
	}
	
	printf("\nCadena invertida utilizando dos arreglos:\n");
	puts(aux);
	
	printf("\nUtilizando un arreglo y un auxiliar:\n");
	puts(string);
	
	printf("\n------- Fin -------\n\n");
	
	system("pause");
	
	return 0;
}