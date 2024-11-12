#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void main(){
    FILE *optab, *source, *intermediate, *symtab, *prgmlength;
    source = fopen("source.txt","r");
    optab = fopen("optab.txt", "r");
    intermediate = fopen("intermediate.txt", "w");
    symtab = fopen("symtab.txt", "w+");
    prgmlength = fopen("length.txt", "w");

    int label[20], opcode[20], operand[20], symtab_data, optab_data;
}