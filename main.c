#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int calculateResult(int op1, int op2, char opr) {
    switch (opr)
    {
    case '+':
        return op1+op2;
        break;
    case '-':
        return op1-op2;
        break;
    case '*':
        return op1*op2;
        break;
    case '/':
        return op1/op2;
        break;
    case '%':
        return op1%op2;
        break;
    default:
        break;
    }
}

void main() {
    char exp[10], input[10];

    printf("Enter the expression : ");
    fgets(exp, sizeof(exp), stdin);

    int k = 0;
    for (int i = 0 ; exp[i] != '\0'; i++) {
        // code to remove whitespaces
        //probably can be done mre efficiently
        if (exp[i] != ' '){ 
            input[k] = exp[i];
            k++;
        }
    }
    input[k] = '\0';
    printf("Entered expression is %s", input);

    int operand1, operand2;
    k = 0;
    char operand[10];
    while(input[k] != '\0'){
        
        if (isdigit(input[k])) {
            operand[k] = input[k];
            k++;
            continue;
        }
        break;
    }
    operand[k] = '\0';
    operand1 = atoi(operand);
    char operator = input[k];
    k++;
    strcpy(operand, "");
    int i =0;
    while(input[k] != '\0') {
        if(isdigit(input[k])) {
            operand[i] = input[k];
            k++;
            i++;
            continue;
        }
        break;
    }
    operand[i] = '\0';
    operand2 = atoi(operand);
    printf("Operand 1 : %d\nOperand 2 : %d\nOperator : %c\n", operand1, operand2, operator);
    printf("Output : %d", calculateResult(operand1, operand2, operator));
}