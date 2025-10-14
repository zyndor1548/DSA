#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	int data;
	struct Node *link;
};

struct Node *head;

void push(int val) {
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->link = head->link;
	head->link = temp;
	temp->data = val;
}

int pop() {
	struct Node *temp;
	if (head->link == NULL) {
		printf("There is nothing to delete\n");
		return 0;
	}
	temp = head->link;
	head->link = temp->link;
	int returnval = temp->data;
	free(temp);
	return returnval;
}

int LastOperator() { return head->link->data; }

int IsOperator(char operator) {
	switch (operator) {
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

int GetPrecedence(char operator) {
	switch (operator) {
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

void PInsert(char val) {
	static int end = 0;
	postfix[end++] = val;
}

void strrev(char *str) {
	int length = strlen(str);
	int start = 0;
	int end = length - 1;
	char temp;
	while (start < end) {
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

int main() {
	head = (struct Node *)malloc(sizeof(struct Node));
	head->link = NULL;
	char infix[64];
	printf("Enter infix string : ");
	scanf("%s", infix);
	strrev(infix);
	int len = strlen(infix);
	infix[len] = '(';
	infix[++len] = '\0';
	push(')');
	for (int i = 0; i < len; i++) {
		if (infix[i] == ')') {
			push(infix[i]);
			continue;
		}
		if (IsOperator(infix[i])) {
			if (infix[i] == '(') {
				while (LastOperator() != ')') {
					PInsert(pop());
				}
				pop();
				continue;
			}
			if (i != 0) {
				while (GetPrecedence(LastOperator()) >=
					   GetPrecedence(infix[i])) {
					PInsert(pop());
				}
			}
			push(infix[i]);
			continue;
		}
		PInsert(infix[i]);
	}
	strrev(postfix);
	PInsert('\0');
	printf("Prefix: %s\n", postfix);
	free(head);
	return 0;
}
