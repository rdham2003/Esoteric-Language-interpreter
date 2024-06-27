#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define brainFuckLen 30000
#define maxCmdLen 1000

int pointer = 0;
char cmd[maxCmdLen];
char brainFuckInput;

int cmdCount = 0;

void commands(char token, unsigned char *brainFuck, char *cmd){
    switch (token){
        case '>':
            if (pointer == brainFuckLen){
                pointer = 0;
                cmdCount++;
            }
            else{
                pointer++;
                cmdCount++;
            }
            break;
        case '<':
            if (pointer < 0){
                pointer = brainFuckLen-1;
                cmdCount++;
            }
            else{
                pointer--;
                cmdCount++;
            }
            break;
        case '+':
            brainFuck[pointer]++;
            cmdCount++;
            break;
        case '-':
            brainFuck[pointer]--;
            cmdCount++;
            break;
        case '.':
            // printf("%d\n", brainFuck[pointer]);
            printf("%c", brainFuck[pointer]);
            cmdCount++;
            break;
        case ',':
            scanf(" %c", &brainFuckInput);
            brainFuck[pointer] = brainFuckInput;
            cmdCount++;
            break;
        case '[':
            if (brainFuck[pointer] == 0){
                while (cmd[cmdCount] != ']'){
                    if (pointer == brainFuckLen){
                        printf("Error: Infinite loop\n");
                        exit(0);
                    }
                    cmdCount++;
                }
            }
            break;
        case ']':
        if (brainFuck[pointer] != 0){
                while (cmd[cmdCount] != '['){
                    if (pointer == 0){
                        printf("Error: Infinite loop\n");
                        exit(0);
                    }
                    cmdCount--;
                }
            }
            break;
        default:
            printf("Invalid Brainfuck Command\n");
            break;
    }
}

int main(int arc, char ** argv){
    unsigned char brainFuck[brainFuckLen];
    for (int i = 0; i < brainFuckLen; i++){
        brainFuck[i] = 0;
    }
    printf("Brainfuck Command: ");
    scanf("%s", cmd);
    int cmdLen = strlen(cmd);
    for (int i = 0; i < cmdLen; i++){
        commands(cmd[i], brainFuck, cmd);
    }
    return 0;
}