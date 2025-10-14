#include <stdio.h>

int top = -1, max, stack[50];

void push() {
	if (top >= max - 1) {
		printf("stack overflow\n");
		return;
	}
	printf("enter value to push : ");
	top += 1;
	scanf("%d", &stack[top]);
}
void pop() {
	if (top == -1) {
		printf("stack underflow\n");
		return;
	}
	top -= 1;
}
void display() {
	if (top == -1) {
		printf("stack is empty\n");
	}
	printf("stack --> \n");
	for (int i = top; i >= 0; i--) {
		printf("%d \n", stack[i]);
	}
	printf("\n");
}

int main() {
	printf("Enter total number of elements in the stack : ");
	scanf("%d", &max);
	int menu;
	do {
		printf("\tstack menu\n");
		printf("\t1. display\n");
		printf("\t2. push\n");
		printf("\t3. pop\n");
		printf("\t4. exit\n");
		printf("\t enter choice : ");
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
			printf("exiting...");
			break;
		default:
			printf("Invalid input");
		}
	} while (menu != 4);
	return 0;
}
