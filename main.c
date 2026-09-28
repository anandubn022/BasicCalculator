#include <stdio.h>

void main() {
    char exp[10];


    printf("Enter the expression : ");
    fgets(exp, sizeof(exp), stdin);
    printf("Entered expression is %s", exp);
}