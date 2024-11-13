#include <stdio.h>
#include "stack.h"

int main() {

    int parenthesis = 1;
    char scanned = 0, last_was_number = 0;

    stack * operands  = create_stack();
    stack * operators = create_stack();

    scanf("%*c");

    while(parenthesis) {

        scanf("%c", &scanned);
        if(scanned == ' ') {
            last_was_number = 0;
            continue;
        }

        if(scanned == '(') parenthesis++;
        else if(scanned == ')') {   //Remove two numbers from the stack and an operator
            //NOT IMPLEMENTED!!!
            last_was_number = 0;
        }
        else if(scanned == '+' || scanned == '-' || scanned == '*' || scanned == '/') {
            char * operator = (char *) calloc(1, sizeof(char));
            *operator = scanned;
            push(operators, operator);

            last_was_number = 0;
        }
        else {
            if(last_was_number) {
                int * num = pop(operands);
                *num *= 10 + ((int)scanned - 48);
                push(operands, num);
            }
            else {
                int * num = (int *) calloc(1, sizeof(int));
                *num = (int)scanned - 48;
                push(operands, num);
            }
        }

    }

return 0;
}