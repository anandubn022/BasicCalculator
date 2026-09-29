#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void calculateResult(char outputString[], int op1, int op2, char opr) {
    int outputInt;
    switch (opr)
    {
    case '+':
        outputInt =  op1+op2;
        sprintf(outputString, "%d", outputInt);
        break;
    case '-':
        outputInt =  op1-op2;
        sprintf(outputString, "%d", outputInt);
        break;
    case '*':
        outputInt =  op1*op2;
        sprintf(outputString, "%d", outputInt);
        break;
    case '/':
        outputInt =  op1/op2;
        sprintf(outputString, "%d", outputInt);
        break;
    case '%':
        outputInt =  op1%op2;
        sprintf(outputString, "%d", outputInt);
        break;
    default:
        strcpy(outputString, "Invalid Input");
        break;
    }

}

void separateExpression(char input[], int *operand1, int *operand2, char *operator) {
    int k = 0;
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
    *operand1 = atoi(operand);
    *operator = input[k];
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
    *operand2 = atoi(operand);
}

int precedenceOf(char x) {
    if (x == '^') {
        return 3;
    }
    else if (x == '*' || x == '/' || x == '%') {
        return 2;
    }
    else if (x == '+' || x == '-') {
        return 1;
    }
    else {
        return 0;
    }
}

void toPostfix(char input[], char output[]) {
    char stack[20];
    int k=0, top = -1;
    for (int i=0; i<strlen(input); i++) {
        if (isdigit(input[i])) {
            output[k++] = input[i];
        }
        else if (input[i] == '(') {
            stack[++top] = input[i];
        }
        else if (input[i] == ')') {
            while(stack[top] != '(') {
                output[k++] = stack[top];
                top--;
            }
            top--;
        }
        else {  //  operator
            while (top != -1 && stack[top] != '(' && precedenceOf(stack[top]) >= precedenceOf(input[i])){
                output[k++] = stack[top];
                top--;
            }
            stack[++top] = input[i];
        }
    }
    while (top != -1){
            output[k++] = stack[top];
            top--;
    }
    output[k] = '\0';
}

void  readExpression(char input[]) {
    char exp[30];

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
}

void main() {
    char input[20], outputString[20];
    readExpression(input);

    /*
    int operand1, operand2;
    char operator;
    separateExpression(input, &operand1, &operand2, &operator);

    // printf("Operand 1 : %d\nOperand 2 : %d\nOperator : %c\n", operand1, operand2, operator);    //  for debug
    char outputString[20];
    calculateResult(outputString, operand1, operand2, operator);
    printf("Output : %s", outputString);
    */

    /*
        to change
        1. add postfix expression conversion
        2. add postfix calculation
    */

    toPostfix(input, outputString);
    printf("Postfic Expression : %s\n", outputString);
}