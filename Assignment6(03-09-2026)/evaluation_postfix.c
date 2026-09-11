/*A simple calculator receives an infix expression. It must:
     Evaluate the postfix expression.
     Sample input 3+4*5
     Sample input (6+2)*3
*/
    #include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++)
    {
        c = infix[i];

        if (isdigit(c))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();

            pop();   // remove '('
        }
        else
        {
            while (top != -1 && peek() != '(' &&
                   precedence(peek()) >= precedence(c))
            {
                postfix[j++] = pop();
            }

            push(c);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[])
{
    int values[MAX];
    int vtop = -1;
    int i, a, b;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
        {
            values[++vtop] = postfix[i] - '0';
        }
        else
        {
            b = values[vtop--];
            a = values[vtop--];

            switch (postfix[i])
            {
                case '+':
                    values[++vtop] = a + b;
                    break;

                case '-':
                    values[++vtop] = a - b;
                    break;

                case '*':
                    values[++vtop] = a * b;
                    break;

                case '/':
                    values[++vtop] = a / b;
                    break;
            }
        }
    }

    return values[vtop];
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    printf("Result: %d\n", evaluatePostfix(postfix));

    return 0;
}