Title CadenaInvertida

;**********************************************************
;* Programa que invierte el orden de los caracteres que   *
;*                conforman a una cadena                  *
;**********************************************************

.386
.model flat, stdcall
.stack 4096

ExitProcess PROTO, dwExitCode:DWORD

.data

origen BYTE "cadena_de_prueba", 0
destino BYTE SIZEOF origen DUP(?)

.code

 main PROC

    mov eax, 0
	mov esi, 0                       ; indice de la cadena origen
	mov edi, SIZEOF destino          ; indice de la cadena destino
    mov ecx, LENGTHOF origen

	call invertir
	call mostrar_cadena

	INVOKE ExitProcess, 0

 main ENDP


 invertir PROC

    push ecx
	mov esi, 0

    L1:

	   mov al, origen[esi]
	   mov destino[edi], al         ; Se realiza intercambio

	   dec edi                      ; Apuntamos al elemento anterior en la cadena "destino"
	   inc esi                      ; Apuntamos al siguiente elemento en la cadena "origen"
	   
	loop L1

	; A "cadena_de_prueba" le corresponde la sucesion de hexadecimales: 63 61 64 65 6e 61 5F 64 65 5F 70 72 75 65 62 61

	pop ecx

	ret

 invertir ENDP


 mostrar_cadena PROC

    mov edi, OFFSET destino
	mov eax, 0

	L2:

	   inc edi
	   mov al, [edi]

	loop L2

	; Ahora en destino se encuentra la cadena "": 61 62 65 75 72 70 5f 65 64 5f 61 6e 65 64 61 63
	; lo cual corresponde a la cadena "abeurp_ed_anedac"

	ret

 mostrar_cadena ENDP

END main