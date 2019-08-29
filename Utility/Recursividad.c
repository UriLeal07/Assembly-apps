/************************************************
* Programador: Uri Leal                          
* Construido en C bajo la IDE Dev-C++ v5.7.1     
* "Resolviendo problemas utilizando recursion"  
* Benemerita Universidad Autonoma de Puebla    
************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define max 60

int pow(int x, int n);
char menu(void);

main()
{
	bool exit = false;
	int arreglo[max];
	int base, exp, x;
	
	printf("\nPrograma para conversion entre dos bases numericas.\n");
	
	do
	{
	
	    switch(menu())
	    {
	    	
		    case 'a':
		    	
		    	printf("Ingresa Base y despues exponente:");
		    	scanf("%d", &base);
		    	scanf("%d", &exp);
		    	printf("\n %d ",pow(base, exp));
		    	printf("\n+-----------------------------------------+\n");
	            system("pause");
	            system("cls");
		        fflush(stdin);
			
		    break;
		
		    case 'b':
		    	
			    
			    printf("\n+-----------------------------------------+\n");
			    system("pause");
			    system("cls");
			    fflush(stdin);
		    
		    break;
		    
		    case 'c':
		    	
		    	
                printf("\n+-----------------------------------------+\n");
			    system("pause");
			    system("cls");
                fflush(stdin);
                
            break;
            
            case 'd':
		    	
		    	
                printf("\n+-----------------------------------------+\n");
			    system("pause");
			    system("cls");
                fflush(stdin);
                
            break;
            
        	case 'e':
		    	
		    	
                printf("\n+-----------------------------------------+\n");
			    system("pause");
			    system("cls");
                fflush(stdin);
                
            break; 
            
		    case 'f':
		    	
		    	
                printf("\n+-----------------------------------------+\n");
			    system("pause");
			    system("cls");
                fflush(stdin);
                
            break; 
		    
		    case 's':
		    	
		    	exit = true;
		    	
		    break;	
		
		    default:
		    	
			    printf("\nLetra incorrecta\n");
			    fflush(stdin);
	    }
	
	}while(!exit);
	
	system("pause");
	
   return 0;
}


char menu(void)
{
	char op;
	
	printf("\nIngrese la opcion deseada.\n");
	printf("\n+------------------------------------------------------------+\n");
	printf("| Calcular funcion exp (x^y)                           ==> (a) |\n");
	printf("| Restar dos numeros                                   ==> (b) |\n");
	printf("| Dividir dos numeros                                  ==> (c) |\n");
	printf("| Obtener elemento minimo de un arreglo                ==> (d) |\n");
	printf("| Obtener la posicion de un elemento en un arreglo     ==> (e) |\n");
	printf("| Sumatoria iterativa y recursiva                      ==> (f) |\n");
	printf("| Salir                                                ==> (s) |\n");
	printf("+--------------------------------------------------------------+\n");
	fflush(stdin);
	op = getchar();
	
	system("cls");
	
  return op;	
}

int pow(int x, int n)
{
	
	if(n == 0)
	    return 1;
    
	else
	    return x * pow(x,n-1);
}

int resta(int x, int y)
{
    if(y == 0)
		return 1;
            
	return (x - resta(x,y-1));
}

        int sumatoriaRecursiva(int n, int i)
        {
            if(i == 0)
                return 1;
            
            else
                return (n + sumatoriaRecursiva(n, i-1));
        }