#include <stdio.h>
#include <ctype.h>

char stack[20];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x) {
    if (x == '(')
        return 0;
    else if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return -1; // Default case for non-operators
}

int main() {
    char exp[20];
    char *e, x;

    printf("Enter the expression: ");
    scanf("%s", exp); // No '&' needed for arrays

    e = exp;
    while (*e != '\0') { // Correct null-terminator check
        if (isalnum(*e)) {
            printf("%c", *e);
        } else if (*e == '(') {
            push(*e);
        } else if (*e == ')') {
            while ((x = pop()) != '(')
                printf("%c", x);
        } else {
            while (top != -1 && priority(stack[top]) >= priority(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }
    
    while (top != -1) {
        printf("%c", pop());
    }

    return 0;
}
