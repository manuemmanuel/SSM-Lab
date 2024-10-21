ASSUME CS:CODE
CODE SEGMENT
START:
    MOV AX, 0         ; Clear AX to ensure no garbage values
    MOV SI, 3000H     ; Starting address

    ; Load the first 16-bit value
    MOV AX, [SI]      ; Load first 16-bit value into AX
    ADD SI, 2         ; Move SI to the next 16-bit value

    ; Load the second 16-bit value
    MOV BX, [SI]      ; Load second 16-bit value into BX

    ; Perform the addition
    ADD AX, BX        ; Add the two 16-bit values

    ; Store the result
    INC SI            ; Move SI to the next available address
    MOV [SI], AX      ; Store the result (16 bits)

    ; Check for carry
    JC L1             ; If carry is set, jump to L1
    INC SI            ; Move SI to the next address
    MOV [SI], 0       ; No carry, store 0 at the next address
    INT 3             ; Breakpoint for debugging
    JMP END           ; Exit

L1: 
    INC SI            ; Move SI to the next address
    INC AX            ; Increment AX to indicate carry
    MOV [SI], AX      ; Store carry value at the next address
    INT 3             ; Breakpoint for debugging

END:
CODE ENDS
END START
