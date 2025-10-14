#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
	int data;
	struct Node *link;
};
struct Node *head;

void push(int val) {
	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->link = head->link;
	head->link = temp;
	temp->data = val;
}
int pop() {
	struct Node *temp;
	if (head->link == NULL) {
		printf("There is nothing to delete");
		return 0;
	}
	temp = head->link;
	head->link = temp->link;
	int retrunval = temp->data;
	free(temp);
	return retrunval;
}
int IsOperator(char operator) {
	switch (operator) {
	case '^':
	case '*':
	case '/':
	case '+':
	case '-':
		return 1;
	default:
		return 0;
	}
}
int evaluate(int num1, int num2, char op) {
	int result;

	switch (op) {
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;

		break;
	case '*':
		result = num1 * num2;

		break;
	case '/':
		if (num2 != 0) {
			result = num1 / num2;
		}
		break;
	case '^':
		for (int i = 0; i < num2 - 1; i++) {
			result = num1 * num1;
		}
		break;
	}
	return result;
}
int getint(char a) { return a - '0'; }
int main() {
	head = (struct Node *)malloc(sizeof(struct Node));
	head->link = NULL;
	char postfix[64];
	printf("Enter postfix string : ");
	scanf("%s", postfix);
	int len = strlen(postfix);
	for (int i = 0; i < len; i++) {
		if (IsOperator(postfix[i]) == 1) {
			int a = pop();
			int b = pop();
			int val = evaluate(b, a, postfix[i]);
			push(val);
		} else {
			push(getint(postfix[i]));
		}
	}
	printf("ans = %d\n", pop());
	free(head);
	return 1;
}
