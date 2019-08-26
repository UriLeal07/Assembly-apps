#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15

char menu(void);
void conversion(double x, char tipo[MAX]);
 

main()
{
	bool exit = false;
	double x;
	char op;
	char c[MAX] = "Centigrados", f[MAX] = "Fahrenheit", k[MAX] = "Kelvin";
	
	do
	{
		op = menu();
		
		switch(op)
	    {
	    	
		    case 'c':
		    			
			    printf("\nIngresa la cantidad de grados Centigrados:\n");
			    scanf("%lf",&x);
			    conversion(x, c);
			    getchar();
			
	    	break;
		
		
	    	case 'f':
			
		    	printf("\nIngresa la cantidad de grados Fahrenheit:\n");
	    	    scanf("%lf",&x);
		        conversion(x, f);
		        getchar();
		
	    	break;
		
		
	    	case 'k':
	  		
	    		printf("\nIngresa la cantidad de grados Kelvin:\n");
		        scanf("%lf",&x);
		        conversion(x, k);
		        getchar();

	    	break;
		
		
	    	case 's':
			
		    	exit = true;
			
	    	break;
	    	
	    	default:
			 
			    printf("\nLetra equivacada.\n");
			    getchar();
	    }
	    
	}while(!exit);
	
	system("pause");

  return 0;
}

char menu(void)
{
	char op;
	
	printf("\n+---------------------------------------------+\n");
	printf("| Ingrese la opcion deseada.                  |\n");
	printf("| Convertir grados centigrados        ==> (c) |\n");
	printf("| Convertir grados fahrenheit         ==> (f) |\n");
	printf("| Convertir grados Kelvin             ==> (k) |\n");
	printf("| Salir                               ==> (s) |\n");
	printf("+---------------------------------------------+\n");
	op = getchar();
	
	system("cls");
	
  return(op);	
}


void conversion(double x, char tipo[MAX])
{
	double res;
	
	if(strcmp(tipo, "Centigrados") == 0)
	{
		printf("\n%.3f grados %s es igual a:\n", x, tipo);
		res = (x*1.8)+32;
		printf("%.3f grados Fahrenheit\n", res);
		res = x+273.15;
		printf("%.3f grados Kelvin\n", res);
    }
    
	else if(strcmp(tipo, "Fahrenheit") == 0)
	{	    
	    printf("\n%.3f grados %s es igual a:\n", x, tipo);
	    res = (x-32)/1.8;
	    printf("%.3f grados Centigrados\n", res);
	    res = res+273.15;
	    printf("%.3f grados Kelvin\n", res);
    }
    
	else if(strcmp(tipo, "Kelvin") == 0)
	{   
	    printf("\n%.3f grados %s es igual a:\n", x, tipo);
	    res = x-273.15;
	    printf("%.3f grados Centigrados\n", res);
	    res = (res*1.8)+32;
	    printf("%.3f grados Fahrenheit\n", res);
    }
    
	else printf("\nError desconocido.\n");

  return;
}
