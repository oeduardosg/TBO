#include <stdio.h>
#include "stack.h"
#include <time.h>

double operation(double num1, double num2, char op) {

    switch (op) {
        case '+':
            return num2 + num1;
        case '-':
            return num2 - num1;
        case '/':
            return num2 / num1;
        case '*':
            return num2 * num1;
    }

}

int main() {

    int parenthesis = 1;
    char scanned = 0, last_was_number = 0;

    stack * operands  = create_stack();
    stack * operators = create_stack();

    scanf("%*c");

    clock_t start, stop;
    start = clock();

    while(parenthesis) {

        scanf("%c", &scanned);
        if(scanned == ' ') {
            last_was_number = 0;
            continue;
        }

        if(scanned == '(') parenthesis++;
        else if(scanned == ')') {   //Remove two numbers from the stack and an operator
            double * num1 = pop(operands);
            double * num2 = pop(operands);
            char * op = pop(operators);
            *num1 = operation(*num1, *num2, *op);
            push(operands, num1);
            free(num2);
            free(op);
            parenthesis--;
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
                double * num = pop(operands);
                *num *= 10 + ((double)scanned - 48);
                push(operands, num);
            }
            else {
                double * num = (double *) calloc(1, sizeof(double));
                *num = (double)scanned - 48;
                push(operands, num);
                last_was_number = 1;
            }
        }

    }

    double * final = pop(operands);
    printf("%.2lf", *final);
    free(final);
    free_stack(operands);
    free_stack(operators);

    stop = clock();
    double time_taken = ((double) stop - start) / CLOCKS_PER_SEC;
    printf("\ntime: %lf\n", time_taken);

return 0;
}