#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head = NULL, *tail = NULL;
void createNode() {
	struct node *newnode;
	int data;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d", &data);
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;
	if (head == NULL) {
		head = tail = newnode;
	} else {
		tail->next = newnode;
		newnode->prev = tail;
		tail = newnode;
	}
	printf("Node Created.\n");
}
void displayForward() {
	struct node *temp = head;
	if (temp == NULL) {
		printf("List is empty.\n");
	} else {
		printf("List (Forward): ");
		while (temp != NULL) {
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}
void displayBackward() {
	struct node *temp = tail;
	if (temp == NULL) {
		printf("List is empty.\n");
	} else {
		printf("List (Backward): ");
		while (temp != NULL) {
			printf("%d ", temp->data);
			temp = temp->prev;
		}
		printf("\n");
	}
}
void insertAtBeginning() {
	struct node *newnode;
	int data;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d", &data);
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = head;
	if (head != NULL)
		head->prev = newnode;
	else
		tail = newnode;
	head = newnode;
	printf("Node inserted at beginning.\n");
}
void insertAtEnd() {
	struct node *newnode;
	int data;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d", &data);
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = tail;
	if (tail != NULL)
		tail->next = newnode;
	else
		head = newnode;
	tail = newnode;
	printf("Node inserted at end.\n");
}
void deleteFromBeginning() {
	struct node *temp;
	if (head == NULL) {
		printf("List is empty.\n");
	} else {
		temp = head;
		head = head->next;
		if (head != NULL)
			head->prev = NULL;
		else
			tail = NULL;
		printf("Deleted node with data %d\n", temp->data);
		free(temp);
	}
}
void deleteFromEnd() {
	struct node *temp;
	if (tail == NULL) {
		printf("List is empty.\n");
	} else {
		temp = tail;
		tail = tail->prev;
		if (tail != NULL)
			tail->next = NULL;
		else
			head = NULL;
		printf("Deleted node with data %d\n", temp->data);
		free(temp);
	}
}
int main() {
	int choice;
	while (1) {
		printf("\n--- DOUBLY LINKED LIST MENU ---\n");
		printf("1. Create Node\n");
		printf("2. Display Forward\n");
		printf("3. Display Backward\n");
		printf("4. Insert at Beginning\n");
		printf("5. Insert at End\n");
		printf("6. Delete from Beginning\n");
		printf("7. Delete from End\n");
		printf("8. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		if (choice == 1)
			createNode();
		else if (choice == 2)
			displayForward();
		else if (choice == 3)
			displayBackward();
		else if (choice == 4)
			insertAtBeginning();
		else if (choice == 5)
			insertAtEnd();
		else if (choice == 6)
			deleteFromBeginning();
		else if (choice == 7)
			deleteFromEnd();
		else if (choice == 8)
			exit(0);
		else
			printf("Invalid choice! Try again.\n");
	}
	return 0;
}