TITLE Promedio, Maximo y Minimo

; ******************************************************
; * Programa que obtiene el promedio, el maximo y el   *
; *        minimo de un conjunto de enteros            *
; ******************************************************

.386
.model flat, stdcall
.stack 4096

ExitProcess PROTO, dwExitCode:DWORD

.data

arreglo SDWORD 8, 3, 6, 1, 0, 4, 19, 20, 101, 54

prom SDWORD ?
mayor SDWORD ?
menor SDWORD ?

.code

 main PROC

   mov esi, OFFSET arreglo                        ; ESI apunta al arreglo
   mov ecx, LENGTHOF arreglo                      ; ECX tiene la longitud del arreglo

   call Promedio                                  ; Calcula el promedio
   call Maximo                                    ; Calcula el elemento maximo
   call Minimo                                    ; Calcula el elemento minimo

   mov eax, prom
   mov ebx, mayor
   mov ecx, menor

   INVOKE ExitProcess, 0

 main ENDP

 ;+--------------------------------------------------------------------------+
 ;|                         Funcion "Promedio"                               |
 ;| Calcula el promedio de un arreglo de enteros de 32-bits.                 |
 ;| Recibe: ESI = offset del arreglo, ECX = No de elementos del arreglo      |
 ;| Modifica: prom = variable que almacena el valor promedio del arreglo     |
 ;+--------------------------------------------------------------------------+

 Promedio PROC

   push esi                                       ; Guardamos ESI y ECX en el stack
   push ecx

   mov eax, 0                                     ; Limpiamos registros
   mov ebx, 0

   Suma:

      add eax, [esi]                                 ; Agrega cada entero a la suma 
      add esi, TYPE DWORD                            ; Apunta al siguiente entero

   loop Suma                                       ; Repite el ciclo para el tamano del arreglo (ecx)

   pop ecx                                        ; Recuperamos ECX y ESI del stack
   pop esi

   mov ebx, ecx                                   ; Movemos a EBX el tamano del arreglo que esta en ECX
   mov edx, 0                                     ; Ponemos en ceros el registro donde se guardara la parte decimal
   idiv ebx                                       ; Dividimos la suma de los elementos del arreglo entre su tamano (EAX/EBX)
   mov prom, eax                                  ; Guardamos el resultado en la variable prom

   ret

 Promedio ENDP


 ;+--------------------------------------------------------------------------+
 ;|                         Funcion "Maximo"                                 |
 ;| Define el elemento maximo de los elementos dentro del arreglo            |
 ;| Recibe: ESI = offset del arreglo, ECX = No de elementos del arreglo      |
 ;| Modifica: mayor = variable que almacena el elemento maximo del arreglo   |
 ;+--------------------------------------------------------------------------+


 Maximo PROC

   mov eax, 0                                     ; Limpiamos Registros
   mov ebx, 0

   push esi                                       ; Guardamos ESI y ECX en el stack
   push ecx

   dec ecx
   mov eax, [esi]
   
   Max:

	  cmp eax, [esi+4]
	  jge es_mayor                                ; Saltamos si eax >= [esi+4]

	  mov eax, [esi+4]

	  es_mayor:

	  add esi, TYPE DWORD

   loop Max

   pop ecx
   pop esi

   mov mayor, eax                                 ; Guardamos el resultado en la variable mayor

   ret

 Maximo ENDP


 ;+--------------------------------------------------------------------------+
 ;|                         Funcion "Minimo"                                 |
 ;| Define el elemento minimo de los elementos dentro del arreglo            |
 ;| Recibe: ESI = offset del arreglo, ECX = No de elementos del arreglo      |
 ;| Modifica: menor = variable que almacena el elemento minimo del arreglo   |
 ;+--------------------------------------------------------------------------+


 Minimo PROC

   mov eax, 0                                     ; Limpiamos Registros
   mov ebx, 0

   push esi                                       ; Guardamos ESI y ECX
   push ecx

   dec ecx
   mov eax, [esi]

   Min:

	  cmp eax, [esi+4]
	  jle es_menor                                 ; Saltamos si eax <= [esi+4]

	  mov eax, [esi+4]

	  es_menor:

	  add esi, TYPE DWORD

   loop Min

   pop esi
   pop ecx

   mov menor, eax                                 ; Guardamos el resultado en la variable mayor

   ret

 Minimo ENDP


END main