#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int data;
    struct Node *link;
};
struct Node *head;

void push(int val)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->link = head->link;
    head->link = temp;
    temp->data = val;
}
int pop()
{
    struct Node *temp;
    if (head->link == NULL)
    {
        printf("There is nothing to delete");
        return 0;
    }
    temp = head->link;
    head->link = temp->link;
    int retrunval = temp->data;
    free(temp);
    return retrunval;
}
int LastOperator()
{
    return head->link->data;
}
int IsOperator(char operator)
{
    switch (operator)
    {
    case '^':
    case '(':
    case ')':
    case '*':
    case '/':
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}
int GetPrecedence(char operator)
{
    switch (operator)
    {
    case '^':
        return 4;
    case '/':
    case '*':
        return 3;
    case '+':
    case '-':
        return 2;
    case '(':
        return 1;
    default:
        return 0;
    }
}
char postfix[64];
void PInsert(char val)
{
    static int end = 0;
    postfix[end++] = val;
    postfix[end] = '\0';
}
int main()
{
    head = (struct Node *)malloc(sizeof(struct Node));
    head->link = NULL;
    char infix[64];
    printf("Enter infix string : ");
    scanf("%s", infix);
    int len = strlen(infix);
    infix[len] = ')';
    infix[++len] = '\0';
    push('(');
    for (int i = 0; i < len; i++)
    {
        if (infix[i] == '(')
        {
            push(infix[i]);
            continue;
        }
        if (IsOperator(infix[i]))
        {
            if (infix[i] == ')')
            {
                while (LastOperator() != '(')
                {
                    PInsert(pop());
                }
                pop();
                continue;
            }
            if (i != 0)
            {
                while (head->link != NULL && GetPrecedence(LastOperator()) >= GetPrecedence(infix[i]))
                {
                    PInsert(pop());
                }
            }
            push(infix[i]);
            continue;
        }
        PInsert(infix[i]);
    }
    printf("postfix : %s", postfix);
    free(head);
    return 1;
}
