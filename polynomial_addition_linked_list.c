#include <stdio.h>
#include <stdlib.h>

struct Node {
	int co, exp;
	struct Node *link;
} *Head[3], *ptr, *ptr1, *ptr2, *temp;
void insert_at_first(struct Node *head, int _co, int _exp) {
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->co = _co;
	temp->exp = _exp;
	temp->link = head->link;
	head->link = temp;
}
void insert(struct Node *head, int _co, int _exp) {
	if (head->link == NULL) {
		insert_at_first(head, _co, _exp);
		return;
	}
	ptr = head->link;
	while (ptr->link != NULL) {
		ptr = ptr->link;
	}
	temp = (struct Node *)malloc(sizeof(struct Node));
	ptr->link = temp;
	temp->link = NULL;
	temp->co = _co;
	temp->exp = _exp;
}
void Display(char *a, struct Node *head) {
	ptr = head->link;
	if (ptr == NULL) {
		printf("Empty polynomial\n");
		return;
	}
	printf("%s : ", a);
	while (ptr->link != NULL) {
		printf("%dx^%d + ", ptr->co, ptr->exp);
		ptr = ptr->link;
	}
	printf("%dx^%d\n", ptr->co, ptr->exp);
}
void Input(struct Node *head) {
	int n;
	printf("Enter number of elements in the polynomial : ");
	scanf("%d", &n);

	if (n <= 0) {
		printf("Invalid number of elements!\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		int _co, _exp;
		printf("Enter coefficient : ");
		scanf("%d", &_co);
		printf("Enter exponent : ");
		scanf("%d", &_exp);
		insert(head, _co, _exp);
	}
}
void Sum() {
	ptr1 = Head[0]->link;
	ptr2 = Head[1]->link;
	while (ptr1 != NULL && ptr2 != NULL) {
		if (ptr1->exp == ptr2->exp) {
			int sum_coeff = ptr1->co + ptr2->co;
			if (sum_coeff != 0) {
				insert(Head[2], sum_coeff, ptr1->exp);
			}
			ptr1 = ptr1->link;
			ptr2 = ptr2->link;
		} else if (ptr1->exp > ptr2->exp) {
			insert(Head[2], ptr1->co, ptr1->exp);
			ptr1 = ptr1->link;
		} else {
			insert(Head[2], ptr2->co, ptr2->exp);
			ptr2 = ptr2->link;
		}
	}
	while (ptr1 != NULL) {
		insert(Head[2], ptr1->co, ptr1->exp);
		ptr1 = ptr1->link;
	}
	while (ptr2 != NULL) {
		insert(Head[2], ptr2->co, ptr2->exp);
		ptr2 = ptr2->link;
	}
}
int main() {
	for (int i = 0; i < 3; i++) {
		Head[i] = (struct Node *)malloc(sizeof(struct Node));
		Head[i]->link = NULL;
	}
	printf("First Polynomial\n");
	Input(Head[0]);
	printf("Second Polynomial\n");
	Input(Head[1]);
	printf("Sum of Polynomials:\n");
	Sum();
	Display("First polynomial", Head[0]);
	Display("Second polynomial", Head[1]);
	Display("sum", Head[2]);
	return 0;
}
