TITLE Conversion_Bases

; ******************************************************
; * Programa que realiza la conversion de bases entre  *
; *           binario-decimal y viceversa              *
; ******************************************************

.386
.model flat, stdcall
.stack 4096

ExitProcess PROTO, dwExitCode:DWORD

.DATA

 BinX DWORD 11010                   ; Numero binario a convertir
 DecX DWORD 103                     ; Numero decimal a convertir

 r_Binario DWORD ?                  ; Resultado en binario
 r_Decimal DWORD ?                  ; Resultado en decimal

 BaseDec DWORD 10                   ; Base divisora Decimal (10)
 BaseBin DWORD 2                    ; Base divisora binaria (2)

 exp DWORD ?                        ; Resultado de elevar 2^n

.CODE

 main PROC
    
	CALL dec_bin
    CALL bin_dec

	MOV eax, r_Binario              ; Mostramos Resultados
	MOV ebx, r_Decimal

	INVOKE ExitProcess, 0

 main ENDP


 dec_bin PROC

    mov eax, 0                      ; Limpiamos registros
	mov ebx, 0
	mov ecx, 0

	mov eax, DecX                   ; EAX es el numero decimal que se va a convertir en binario
	mov ebx, BaseBin                ; EBX es la base binaria (2) por la que vamos a dividir al decimal
	mov ecx, 1                      ; ECX funciona como auxiliar, multiplica a EDX y se multiplica por la base decimal (10)

	l1:
	   
	   mov edx, 0                   ; Limpiamos el registro donde se guarda el residuo
	   idiv ebx
	   imul edx, ecx
	   add r_Binario, edx           ; r_Binario == sumatoria de los residuos de cada division realizada en la iteracion multiplicado * 10
	   imul ecx, BaseDec

	cmp eax, 0                      ; El ciclo termina cuando el cociente es cero (eax == 0)
	jne l1
    
    ret

 dec_bin ENDP


 bin_dec PROC

    mov eax, 0                      ; Limpiamos registros
	mov ebx, 0

	mov ecx, 0                      ; ECX es la potencia a la que se elevara 2, (2^n)
	mov edi, 0                      ; EDI es una copia de ECX para ser utilizada en la funcion "expFun"
	mov esi, 0                      ; ESI se ocupa como auxiliar utilizado en la funcion "expFun"

	mov eax, BinX                   ; EAX es el numero binario que se va a convertir en decimal
	mov ebx, BaseDec                ; EBX es la base binaria (2) por la que vamos a dividir al decimal

	l2:
	   
	   mov edx, 0                   ; Limpiamos el registro donde se guarda el residuo
	   idiv ebx

	   mov esi, 1                   ; Reseteamos el valor auxiliar multiplicativo en ESI
	   call ExpFun                  ; Calculamos 2^n

	   imul edx, exp                ; Multiplicamos el residuo * 2^n
	   add r_Decimal, edx           ; r_Decimal == la sumatoria de los residuos multiplicados * 2^n

	   inc ecx                      ; Incrementamos el valor de la potencia de 2^n
	   mov edi, ecx

	cmp eax, 0                      ; El ciclo termina cuando el cociente es cero (eax == 0)
	jne l2

	mov eax, r_Decimal

 bin_dec ENDP


 ExpFun PROC

    cmp edi, 0                      ; Si EDI == 0 ejecutamos el codigo
	jne case1

	   imul esi, 1
	   mov exp, esi
	   ret

	case1:

	cmp edi, 1                      ; Si EDI >= 1 ejecutamos el codigo
	jl case2

	   imul esi, BaseBin
	   mov exp, esi
	   dec edi

	   call ExpFun

	case2:

	ret

 ExpFun ENDP

END main