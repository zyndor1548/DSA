#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *link;
} *head, *ptr, *temp;

void display() {
	temp = head->link;
	while (temp != NULL) {
		printf("%d --> ", temp->data);
		temp = temp->link;
	}
	printf("NULL\n");
}
void insert_at_first() {
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->link = head->link;
	head->link = temp;
	printf("Enter value : ");
	scanf("%d", &temp->data);
}
void enqueue() {
	if (head->link == NULL) {
		insert_at_first();
		return;
	}
	ptr = head->link;
	while (ptr->link != NULL) {
		ptr = ptr->link;
	}
	temp = (struct Node *)malloc(sizeof(struct Node));
	ptr->link = temp;
	temp->link = NULL;
	printf("Enter value : ");
	scanf("%d", &temp->data);
}
void dequeue() {
	if (head->link == NULL) {
		printf("empty list");
		return;
	}
	ptr = head->link;
	head->link = ptr->link;
	free(ptr);
	printf("removed from frist\n");
}
void exit_linked_list() {
	ptr = head->link;
	while (ptr != NULL) {
		temp = ptr->link;
		free(ptr);
		ptr = temp;
	}
	free(head);
	printf("exiting...\n");
}
int main() {
	int menu;
	head = (struct Node *)malloc(sizeof(struct Node));
	head->link = NULL;
	do {
		printf("\tqueue menu\n");
		printf("\t1. display\n");
		printf("\t2. enqueue\n");
		printf("\t3. dequeue\n");
		printf("\t4. exit\n");
		printf("\t enter choice : ");
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			display();
			break;
		case 2:
			enqueue();
			break;
		case 3:
			dequeue();
			break;
		case 4:
			exit_linked_list();
			break;
		default:
			printf("Invalid input\n");
		}
	} while (menu != 4);
	return 0;
}
