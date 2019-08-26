TITLE Conversion de temperaturas

;******************************************************
;* Programa que convierte grados centígrados a grados *
;*             fahrenheit y viceversa                 *
;******************************************************


; Para converir °F a °C ==> (°F - 32) * 5/9

; Para converir °C a °F ==> (°C * 9/5) + 32


.386
.model flat, stdcall
.stack 4096

ExitProcess PROTO, dwExitCode:DWORD

.data

num SDWORD 9                 ; Numerador = 9         ========>  Fracción 9/5
den SDWORD 5                 ; Denominador = 5
const SDWORD 32              ; Constante = 32
cent SDWORD 25               ; Grados centígrados
fahr SDWORD -1               ; Grados fahrenheit

.code

main PROC

 call Conversion

 MOV eax, 0
 MOV ebx, 0

 INVOKE ExitProcess, 0

main ENDP


 Conversion PROC

  ;*************************De grados fahrenheit a centígrados*************************

   MOV edx, 0                ; Vaciamos el registro donde se guarda el residuo
   MOV eax, fahr             ; EAX = f grados fahrenheit
   SUB eax, const            ; EAX = EAX - 32
   MOV ebx, den              ; EBX = den (5)
   IMUL ebx                  ; EAX = EBX * EAX
   MOV ebx, num              ; EBX = num (9)
   IDIV ebx                  ; EAX = EAX / EBX

   CMP eax, 0                ; Comparamos si tenemos una respuesta negativa
   JGE esPositivo

      NEG eax                ; Ahora podemos visualizar los resultados en hexadecimal, teniendo en cuenta que son valores negativos.
	  NEG edx

   esPositivo:

  ;*************************De grados centígrados a fahrenheit*************************

   MOV edx, 0                ; Vaciamos el registro donde se guarda el residuo
   MOV eax, cent             ; EAX = c grados centígrados
   IMUL ebx                  ; EAX = EAX * EBX (9) ==> Esto lo hacemos porque ebx ya trae el valor del num.
   MOV ebx, den              ; EBX = den
   IDIV ebx                  ; EAX = EAX / EBX (5)
   ADD eax, const            ; EAX = EAX + 32

   CMP eax, 0                ; Comparamos si tenemos una respuesta negativa
   JGE positivo

      NEG eax                ; Ahora podemos visualizar los resultados en hexadecimal, teniendo en cuenta que son valores negativos.
	  NEG edx

   positivo:

   ret

 Conversion ENDP

END main

END