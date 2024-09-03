#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
   FILE *input, *output, *optab, *symbol;
   input = fopen("input.txt" , "r");
   output = fopen("output.txt" , "w");
   symbol = fopen("symbol.txt" , "w");
   optab = fopen("optab.txt" , "r");
   int locctr, start, length;
   char label[10], opcode[10], operand[10], mneumonic[10], code[10];
   fscanf(input,"%s%s%s", label, opcode, operand);
   if (strcmp(opcode,"START") == 0){
     start = atoi(operand);
     locctr = start;
     fprintf(output,"\t%s\t%s\t%s\n", label, opcode, operand);
     fscanf(input,"%s%s%s",label,opcode,operand);
   }
   else
     locctr=0;
   while (strcmp(opcode,"END")!=0){
      fprintf(output,"%X\t",locctr);
      if (strcmp(label,"**") != 0){
         fprintf(symbol,"%s\t%X\n", label, locctr);
         }
      rewind(optab);
      fscanf(optab,"%s%s",code,mneumonic);
      while (strcmp(code,"END") != 0){
      	if (strcmp(opcode,code) == 0){
            locctr = locctr + 3;
            break;
         }
         fscanf(optab,"%s%s",code,mneumonic);
      }
      if (strcmp(opcode,"WORD") == 0){
          locctr += 3;
          }
      else if (strcmp(opcode,"RESW")==0){
          locctr += 3*atoi(operand);
          }
      else if (strcmp(opcode,"RESB") == 0){           
           locctr += atoi(operand);
           }
      else if (strcmp(opcode,"BYTE") == 0){
           locctr += strlen(operand) - 3;
           }
      fprintf(output,"%s\t%s\t%s\n", label, opcode, operand);
      fscanf(input,"%s%s%s",label, opcode, operand);
   }
   fprintf(output,"%X\t",locctr);
   fprintf(output,"\t%s\t%s\t%s\n", label, opcode, operand);
   length = locctr - start;
   printf("Length of code is: %X\n",length);
   fclose(input);
   fclose(output);
   fclose(optab);
   fclose(symbol);
   return 0;
}
