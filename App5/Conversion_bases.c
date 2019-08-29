/**********************************************
* Programador: Uri Leal                       *
* Construido en C bajo la IDE Dev-C++ v5.7.1  *
* Benemerita Universidad Autonoma de Puebla   *
**********************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 1000
#define DECMAX 32000
#define Tamano 35            //Tamano se fija en 35 porque los enteros de dos bytes ocupan 32 bits


char menu(void);
int a_binario();
int a_decimal();
void a_hexadecimal(int x);
void Lee_arreglo(int a[]);
void hexa_dec(int b[]);


main()
{
	bool exit = false;
	int arreglo[Tamano];
	
	printf("\nPrograma para conversion entre dos bases numericas.\n");
	
	do
	{
	
	    switch(menu())
	    {
	    	
		    case 'a':
		    	
		    	a_hexadecimal(a_decimal());
		    	printf("\n+-----------------------------------------+\n");
	            system("pause");
	            system("cls");
		        fflush(stdin);
			
		    break;
		
		    case 'b':
		    	
			    a_hexadecimal(a_binario());
			    printf("\n+-----------------------------------------+\n");
			    system("pause");
			    system("cls");
			    fflush(stdin);
		    
		    break;
		    
		    case 'c':
		    	
		    	Lee_arreglo(arreglo);
                hexa_dec(arreglo);
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
	
	printf("\n+---------------------------------------------+\n");
	printf("| Ingrese la opcion deseada.                  |\n");
	printf("| Convertir del binario               ==> (a) |\n");
	printf("| Convertir del decimal               ==> (b) |\n");
	printf("| Convertir del hexadecimal           ==> (c) |\n");
	printf("| Salir                               ==> (s) |\n");
	printf("+---------------------------------------------+\n");
	fflush(stdin);
	op = getchar();
	
	system("cls");
	
  return op;	
}



int a_binario()
{
	int k = 0, dec, cociente, v[MAX], length = 0;
	bool fin = false;
	
	do
	{
		printf("\nIngrese la cantidad: \n");
	    scanf("%d", &dec);
	    
	    if(dec <= 0)
	    	printf("\nIngresa positivos.\n");
	    	
	}while(dec <= 0 || dec > DECMAX);
	
	system("cls");
	
	cociente = dec;
	
	while(!fin)
	{
	    v[k] = cociente%2;
			    
		if(cociente/2 <= 0)
			fin = true;
        
        cociente /= 2;
        
		k++;
	}
	
	length = k;
	
	printf("\n\nUsted ingreso %d ", dec);
	  	
	printf("\nEl valor en binario = ");
    for(k = length-1; k >= 0; k--)
	    printf("%d", v[k]);
	
	return dec;
}



int a_decimal()
{
	int aux = 0, n, k = 1, i, v[MAX];
	
	do
	{
		printf("\nDe cuantos digitos es el numero binario?\n");
		fflush(stdin);
	    scanf("%d",&n);
	    
	    if(n <= 0)
	    	printf("\nDebe ingresar cantidades de al menos un digito.\n");
	    	
	    if(n > MAX)
		    printf("El numero maximo de digitos es %d", MAX);
				
	}while(n <= 0 || n > MAX);
	
	system("cls");
	
	printf("\nIngrese los digitos de izquierda a derecha.\n");
	
	for(i = n-1; i >= 0; i--, k++)
	{
	    do
	    {
	    	printf("\n\nIngrese el digito #%d: ", k);
	    	fflush(stdin);
		    scanf("%d", &v[i]);
		    
		    if(v[i] != 1 && v[i] != 0)
		    	printf("Solo se aceptan los valores 1 y 0.");
		    
	    }while(v[i] != 1 && v[i] != 0);
		
		
		aux += (v[i] * (pow(2,i)));
		
	}
	
	system("cls");
	printf("\n\nUsted ingreso ");
	
	for(i=n-1;i>=0;i--)
		printf("%d",v[i]);
	    
   	  	
	printf("\nEl valor en decimal es = %d",aux);
	printf("\n+-----------------------------------------+\n");
	
	return aux;
}



void a_hexadecimal(int x)
{
	char hex_array[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	char aux[MAX];
	int i = 0, cociente = x, length, pos;
	bool fin = false;
	
	
	while(!fin)
	{
		pos = cociente%16;
		aux[i] = hex_array[pos];
		
		if(cociente/16 <= 0)
			fin = true;
		
		cociente /= 16;
		
		i++;
	}
	
	length = i;
	  	
	printf("\nEl valor en hexadecimal = ");
    for(i = length-1; i >= 0; i--)
	    printf("%c", aux[i]);
	
}



void Lee_arreglo(int a[])
{
     int k = 0;
     
    // Las entradas se inicializan a ' '
    
     for(k = 0; k < Tamano; k++ )
         a[k] = ' ';

     printf("\nIntroduzca un numero hexadecimal: \n");
     fflush(stdin);
    
	  /*El siguiente while recibe la cadena y la
        asigna al arreglo en una sola linea.
        Observe que al final hay un ;  */

     k = 0;

     while ((a[k++] = getchar()) != '\n' && Tamano > k );
     
     printf("\n");
}



void hexa_dec(int b[])
{
     int i, inicio;
     int potencia = 1;
     int decimal = 0;
     int valido = 1;

     for (i = Tamano-1; i >= 0; i--)
         if (b[i] != ' ')
         {
             inicio = i;
             break;
         }

      for (i = inicio; i >= 0; i--)
      {
          switch(b[i])
          {
              case '0':
              	
                  decimal += 0*potencia;
                  potencia *= 16;
                  
              break;
              
              case '1':
              	
                  decimal += 1*potencia;
                  potencia *= 16;
                  
              break;
              
              case '2':
              	
                  decimal += 2*potencia;
                  potencia *= 16;
                  
              break;
              
              case '3':
              	
                  decimal += 3*potencia;
                  potencia *= 16;
                  
              break;
              
              case '4':
              	
                   decimal += 4*potencia;
                   potencia *= 16;
                   
              break;
              
              case '5':
              	
                   decimal += 5*potencia;
                   potencia *= 16;
                   
		      break;
		      
              case '6':
              	
              decimal += 6*potencia;
              potencia *= 16;
              
              break;
              
              case '7':
              	
              decimal += 7*potencia;
              potencia *= 16;
              
              break;
              
              case '8':
              	
              decimal += 8*potencia;
              potencia *= 16;
              
              break;
              
              case '9':
              	
              decimal += 9*potencia;
              potencia *= 16;
              
              break;
              
              case 'A':
              case 'a':
              	
                decimal +=  10*potencia;
                potencia *= 16;
              
              break;
              
              case 'B':
              case 'b':
              	
                decimal +=  11*potencia;
                potencia *= 16;
              
              break;
              
              case 'C':
              case 'c':
              	
                decimal +=  12*potencia;
                potencia *= 16;
              
              break;
              
              case 'D':    
              case 'd':
              	
                decimal +=  13*potencia;
                potencia *= 16;
              
              break;
              
              case 'E':
              case 'e':
              	
                decimal +=  14*potencia;
                potencia *= 16;
              
              break;
              
              case 'F':
              case 'f':
              	
                decimal +=  15*potencia;
                potencia *= 16;
              
              break;
              
              default:
              	
                if ('\n' != b[i])
                {
                    printf("\nERROR! Cadena invalida.\n");
                    valido = 0;
                   
                    printf("\nEste caracter no es valido: ");
                    putchar(b[i]);
                    printf("\n");
                }
              
              break;
          }
      }

      if ( 1 == valido )
         printf("\nEl valor decimal es: %d\n", decimal);
      
      else
         printf("\nEl numero introducido no es valido.\n");
}