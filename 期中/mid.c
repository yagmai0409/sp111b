#include <stdio.h>
#include <string.h>

#define MAX_INSTRUCTION_LENGTH 256
#define MAX_OPCODE_LENGTH 6

typedef struct {
    char opcode[MAX_OPCODE_LENGTH];
    char machineCode[MAX_OPCODE_LENGTH];
} Instruction;

Instruction instructions[] = {
    {"mov", "B8"},
    {"add", "01"},
    // 在這裡可以繼續添加其他的指令和對應的機器碼
};

int main() {
    char instruction[MAX_INSTRUCTION_LENGTH];
    char machineCode[MAX_OPCODE_LENGTH];
    int i;

    printf("請輸入彙編指令：");
    fgets(instruction, sizeof(instruction), stdin);
    instruction[strcspn(instruction, "\n")] = '\0'; // 移除換行符號

    for (i = 0; i < sizeof(instructions) / sizeof(Instruction); i++) {
        if (strcmp(instruction, instructions[i].opcode) == 0) {
            strcpy(machineCode, instructions[i].machineCode);
            printf("機器碼為：%s\n", machineCode);
            return 0;
        }
    }

    printf("找不到對應的彙編指令。\n");
    return 0;
}
