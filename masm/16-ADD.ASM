ASSUME CS:CODE
CODE SEGMENT
START:
    MOV AX, 0000H  ; Clear AX register
    MOV SI, 3000H  ; Set SI to the starting address
    MOV AX, [SI]   ; Load the first 16-bit number into AX
    ADD SI, 2      ; Increment SI to point to the next 16-bit number
    ADD AX, [SI]   ; Add the next 16-bit number to AX
    ADD SI, 2      ; Increment SI to point to the next address
    MOV [SI], AX   ; Store the result back to memory
    JC L1          ; Jump to L1 if there is a carry
    ADD SI, 2      ; Increment SI to point to the next address
    MOV [SI], 0000H ; Store 0 if there is no carry
    INT 3          ; Interrupt to terminate the program
L1:
    ADD SI, 2      ; Increment SI to point to the next address
    MOV [SI], 0001H ; Store 1 if there is a carry
    INT 3          ; Interrupt to terminate the program
CODE ENDS
END START
