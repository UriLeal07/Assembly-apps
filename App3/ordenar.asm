TITLE Ordenar

;**********************************************************
;* Programa que ordena un conjunto de numeros utilizando  *
;*           el metodo burbuja (bubble sort)              *
;**********************************************************

.386
.model flat, stdcall
.stack 4096

ExitProcess PROTO, dwExitCode:DWORD

.data

enteros DWORD 8, 3, 6, 1, 0, 4, 19, 20, 101, 54, 2

.code

 main PROC
    
	mov esi, OFFSET enteros                        ; ESI apunta al arreglo
    mov ecx, LENGTHOF enteros                      ; ECX tiene la longitud del arreglo

	call bubble_sort                               ; Se realiza ordenamiento
	call show_array                                ; Se muestra el arreglo con ayuda de EAX
    
	INVOKE ExitProcess, 0

 main ENDP


 bubble_sort PROC

    push esi
	push ecx

    mov eax, 0                     ; Auxiliar para hacer intercambio
	mov edx, 0                     ; Longitud del arreglo ==> EDX = ECX

	mov edi, ecx                   ; EDI == lengthof enteros

	For1:

	   mov esi, offset enteros                  ; Se inicia desde el primer elemento
	   mov edx, edi                             ; "Reseteamos" el indice del 2do ciclo
	   dec edx

	   For2:

	      mov eax, [esi]

	      cmp eax, [esi+4]
	      jg es_mayor

		     xchg eax, [esi+4]                 ; Se realiza intercambio (swap)
		     mov [esi], eax

	      es_mayor:

	      add esi, TYPE DWORD                  ; Se apunta al siguiente entero
   	      dec edx

	      cmp edx, 0                           ; Termina cuando edx == 0
	      jnz For2

	loop For1

	pop esi
	pop ecx

	ret

 bubble_sort ENDP


 show_array PROC

    mov esi, offset enteros
	mov ecx, LENGTHOF enteros 

	mov eax, 0

	l1:

	   mov eax, [esi]
	   add esi, TYPE DWORD

	loop l1

    ret

 show_array ENDP

 END main