#include <stdio.h>
int num, elements;
int stack_array[400];
void Push(int id);
void Pop(int id);
int GetIndex();
void Display();
#define ID GetIndex()
struct multistack
{
    int min;
    int max;
    int top;
} stack[10];
int StackIndex = -1;
int main()
{
    printf("enter the number of stacks you want : ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        printf("Enter number of elements in %d th stack : ",i);
        scanf("%d", &elements);
        if (StackIndex == -1)
        {
            StackIndex += 1;
            stack[StackIndex].min = 0;
            stack[StackIndex].max = elements - 1;
            stack[StackIndex].top = -1;
        }
        else
        {
            StackIndex += 1;
            stack[StackIndex].min = stack[StackIndex - 1].max + 1;
            stack[StackIndex].max = stack[StackIndex - 1].max + elements;
            stack[StackIndex].top = stack[StackIndex].min - 1;
        }
    }
    Display();
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
            Display();
            break;
        case 2:
            Push(ID);
            break;
        case 3:
            Pop(ID);
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
void Push(int id)
{

    if (stack[id].top + 1 > stack[id].max) {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter value to push: ");
    scanf("%d", &stack_array[++stack[id].top]);
    printf("Pushed %d to the stack.\n", stack_array[stack[id].top]);
}

void Pop(int id)
{
    if (stack[id].top < stack[id].min)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("You popped: %d\n", stack_array[stack[id].top]);
    stack_array[stack[id].top--] = 0;
}

void Display()
{

    printf("Current stack:\n");
    for (int i = stack[StackIndex].max; i >= 0; i--)
    {
        for (int j = StackIndex; j >= 0 ; j--)
            if (stack[j].max == i)
            {
                printf("stack %d\n",j);
                printf("-----\n");
            }
        printf("| %d |\n", stack_array[i]);
        printf("-----\n");
    }
}