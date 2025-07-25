#include <stdio.h>

int top = -1;
int max;
int stack[20];

int push();
int pop();
void display();

int main() {
    printf("Enter number of elements in the stack : ");
    scanf("%d", &max);

    int menu;
    do {
        printf("\nStack Functions");
        printf("\n1. Display");
        printf("\n2. Push");
        printf("\n3. Pop");
        printf("\n4. Exit");
        printf("\nChoose: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                display();
                break;
            case 2:
                push();
                break;
            case 3:
                pop();
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

int push() {
    if (top >= max - 1) {
        printf("Stack Overflow\n");
        return 0;
    }
    printf("Enter value to push: ");
    scanf("%d", &stack[++top]);
    printf("Pushed %d to the stack.\n", stack[++top]);
    return 1;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return 0;
    }
    printf("You popped: %d\n", stack[top--]);
    return 1;
}

void display() {

    printf("Current stack:\n");
    for (int i = max; i >= 0; i--) {
        printf("-----\n");
        printf("| %d |\n", stack[i]);
    }
    printf("-----\n");
}
