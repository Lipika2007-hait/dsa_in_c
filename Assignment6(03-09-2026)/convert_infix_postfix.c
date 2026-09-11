/*Q> A simple calculator receives an infix expression. It must
1. Convert infix expression to postfix
Sample input: 3+4*5
*/

#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int priority(char ch)
{
    if(ch == '+' || ch == '-')
        return 1;
    if(ch == '*' || ch == '/')
        return 2;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for(i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if(isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else
        {
            while(top != -1 && priority(stack[top]) >= priority(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while(top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s", postfix);

    return 0;
}