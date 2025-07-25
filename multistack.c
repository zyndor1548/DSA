#include <stdio.h>
int num, elements;
int stack_array[400];
int push(int id);
int pop(int id);
int GetIndex();
void display();
#define ID GetIndex()
struct multistack
{
    int min;
    int max;
    int top;
} stack[10];
int StackIndex = 0;
int main()
{
    printf("enter the number of stacks you want : ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        printf("Enter number of elements in the stack : ");
        scanf("%d", &elements);
        if (StackIndex == 0)
        {
            stack[StackIndex].min = 0;
            stack[StackIndex].max = elements;
            stack[StackIndex].top = -1;
        }
        else
        {
            StackIndex += 1;
            stack[StackIndex].min = stack[StackIndex - 1].max + 1;
            stack[StackIndex].max = stack[StackIndex - 1].max + elements;
            stack[StackIndex].top = stack[StackIndex - 1].max;
        }
    }

    int menu;
    do
    {
        printf("\nStack Functions");
        printf("\n1. Display");
        printf("\n2. Push");
        printf("\n3. Pop");
        printf("\n4. Exit");
        printf("\nChoose: ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            display();
            break;
        case 2:
            push(ID);
            break;
        case 3:
            pop(ID);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }

    } while (menu != 4);

    return 0;
}
int GetIndex()
{
    int index;
    printf("\n\twhich stack do you want :");
    scanf("%d", &index);
    return index;
}
int push(id)
{
    if (stack[id].top >= stack[id].max)
    {
        printf("Stack Overflow\n");
        return 0;
    }
    printf("Enter value to push: ");
    scanf("%d", &stack_array[++stack[id].top]);
    printf("Pushed %d to the stack.\n", stack_array[stack[id].top]);
    return 1;
}

int pop(id)
{
    if (stack[id].top < stack[id].min)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    printf("You popped: %d\n", stack_array[stack[id].top--]);
    stack_array[stack[id].top] = 0;
    return 1;
}

void display()
{

    printf("Current stack:\n");
    for (int i = stack[StackIndex].max; i >= 0; i--)
    {
        for (int j = 0; j < stack[StackIndex].max; j++)
            if (stack[j].max == i)
            {
                printf("-----\n");
            }
        printf("-----\n");
        printf("| %d |\n", stack_array[i]);
    }
    printf("-----\n");
}
