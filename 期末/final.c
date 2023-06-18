#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INSTRUCTION_LENGTH 256
#define MAX_OPCODE_LENGTH 6
#define MAX_SYMBOL_LENGTH 32

typedef struct {
    char opcode[MAX_OPCODE_LENGTH];
    char machineCode[MAX_OPCODE_LENGTH];
    int numOperands;
    int operandSize;
} Instruction;

typedef struct {
    char symbol[MAX_SYMBOL_LENGTH];
    unsigned int address;
} SymbolTableEntry;

Instruction instructions[] = {
    {"mov", "B8", 2, 4},
    {"add", "01", 2, 4},
    {"sub", "29", 2, 4},
    {"jmp", "E9", 1, 4},
 
};

SymbolTableEntry symbolTable[] = {
    {"address1", 0x1000},
    {"address2", 0x2000},
   
};

int main() {
    char instruction[MAX_INSTRUCTION_LENGTH];
    char machineCode[MAX_OPCODE_LENGTH];
    int numOperands, operandSize, i;

    printf("請輸入彙編指令：");
    fgets(instruction, sizeof(instruction), stdin);
    instruction[strcspn(instruction, "\n")] = '\0'; 

    for (i = 0; i < sizeof(instructions) / sizeof(Instruction); i++) {
        if (strcmp(instruction, instructions[i].opcode) == 0) {
            numOperands = instructions[i].numOperands;
            operandSize = instructions[i].operandSize;

            printf("請輸入操作數：\n");
            for (int j = 0; j < numOperands; j++) {
                char operand[MAX_SYMBOL_LENGTH];
                int isSymbolic = 0;
                unsigned int value;

                printf("操作數 %d：", j + 1);
                scanf("%s", operand);

                for (int k = 0; k < sizeof(symbolTable) / sizeof(SymbolTableEntry); k++) {
                    if (strcmp(operand, symbolTable[k].symbol) == 0) {
                        value = symbolTable[k].address;
                        isSymbolic = 1;
                        break;
                    }
                }

                if (!isSymbolic) {
                    value = strtoul(operand, NULL, 0);
                }

                for (int k = 0; k < operandSize; k++) {
                    machineCode[j * operandSize + k] = (value >> (8 * k)) & 0xFF;
                }
            }

            printf("機器碼為：");
            for (int k = 0; k < numOperands * operandSize; k++) {
                printf("%02X ", (unsigned char)machineCode[k]);
            }
            printf("\n");

            return 0;
        }
    }

    printf("找不到對應的彙編指令。\n");
    return 0;
}
