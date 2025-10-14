#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *link;
} *head, *ptr, *temp;
void create_list();
void display();
void insert_at_first();
void insert_at_last();
void delete_first();
void delete_last();
void insert_in_between();
void delete_from_between();
void exit_linked_list();
int main() {
	create_list();
	int choice, choice2;
	do {
		printf("\tLinked list Menu\n");
		printf("\t1. Insert\n");
		printf("\t2. Delete\n");
		printf("\t3. Display\n");
		printf("\t4. Exit\n");
		printf("Enter Choice : ");
		scanf("%d", &choice);
		switch (choice) {
		case 1: {
			printf("\tLinked list Insertion Menu\n");
			printf("\t1. Insert at First\n");
			printf("\t2. Insert at last\n");
			printf("\t3. Insert In between\n");
			printf("Enter Choice : ");
			scanf("%d", &choice2);
			switch (choice2) {
			case 1:
				insert_at_first();
				break;
			case 3:
				insert_in_between();
				break;
			default:
				insert_at_last();
				break;
			}
			break;
		}
		case 2: {
			printf("\tLinked list Deletetion Menu\n");
			printf("\t1. Delete First\n");
			printf("\t2. Delete last\n");
			printf("\t3. Delete From between\n");
			printf("Enter Choice : ");
			scanf("%d", &choice2);
			switch (choice2) {
			case 1:
				delete_first();
				break;
			case 2:
				delete_from_between();
				break;
			default:
				delete_last();
				break;
			}
			break;
		}
		case 3:
			display();
			break;
		case 4:
			exit_linked_list();
			break;
		default:
			printf("Invalid input !!");
			break;
		}
	} while (choice != 4);
	return 1;
}
void create_list() {
	head = (struct Node *)malloc(sizeof(struct Node));
	head->link = NULL;
	int elements;
	printf("Enter number of elements : ");
	scanf("%d", &elements);
	temp = (struct Node *)malloc(sizeof(struct Node));
	head->link = temp;
	printf("Enter value : ");
	scanf("%d", &temp->data);
	ptr = temp;
	for (int i = 1; i < elements; i++) {
		temp = (struct Node *)malloc(sizeof(struct Node));
		ptr->link = temp;
		temp->link = NULL;
		printf("Enter value : ");
		scanf("%d", &temp->data);
		ptr = temp;
	}
}
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
void insert_at_last() {
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
void delete_first() {
	if (head->link == NULL) {
		printf("empty list");
		return;
	}
	ptr = head->link;
	head->link = ptr->link;
	free(ptr);
	printf("removed from frist\n");
}
void delete_last() {
	if (head->link == NULL) {
		printf("empty list");
		return;
	}
	struct Node *prev;
	ptr = head->link;
	while (ptr->link != NULL) {
		prev = ptr;
		ptr = ptr->link;
	}
	prev->link = NULL;
	free(ptr);
	printf("removed from last\n");
}
void insert_in_between() {
	int choice;
	struct Node *prev;
	printf("\tLinked list Insertion Between Menu\n");
	printf("\t1. Insert at a position\n");
	printf("\t2. Insert before a key\n");
	printf("Enter Choice : ");
	scanf("%d", &choice);
	switch (choice) {
	case 2: {
		int key;
		printf("Enter a key : ");
		scanf("%d", &key);
		ptr = head->link;
		while (ptr != NULL && ptr->data != key) {
			prev = ptr;
			ptr = ptr->link;
		}
		break;
	}
	default: {
		int pos;
		printf("Enter Position : ");
		scanf("%d", &pos);
		if (pos == 0) {
			insert_at_first();
			return;
		}
		ptr = head->link;
		int i;
		for (i = 0; ptr != NULL && i < pos; i++) {
			prev = ptr;
			ptr = ptr->link;
		}
		break;
	}
	}
	if (ptr == NULL) {
		printf("key or pos not in the list\n");
		return;
	}
	temp = (struct Node *)malloc(sizeof(struct Node));
	prev->link = temp;
	temp->link = ptr;
	printf("Enter value : ");
	scanf("%d", &temp->data);
}
void delete_from_between() {
	int choice;
	struct Node *prev;
	printf("\tLinked list deletion Between Menu\n");
	printf("\t1. delete a position\n");
	printf("\t2. delete a key\n");
	printf("Enter Choice : ");
	scanf("%d", &choice);
	switch (choice) {
	case 2: {
		int key;
		printf("Enter a key : ");
		scanf("%d", &key);
		ptr = head->link;
		while (ptr != NULL && ptr->data != key) {
			prev = ptr;
			ptr = ptr->link;
		}
		break;
	}
	default: {
		int pos;
		printf("Enter Position : ");
		scanf("%d", &pos);
		if (pos == 0) {
			delete_first();
			return;
		}
		ptr = head->link;
		int i;
		for (i = 0; ptr != NULL && i < pos; i++) {
			prev = ptr;
			ptr = ptr->link;
		}
		break;
	}
	}
	if (ptr == NULL) {
		printf("key or pos not in the list\n");
		return;
	}
	prev->link = ptr->link;
	free(ptr);
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
