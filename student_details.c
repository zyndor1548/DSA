#include <stdio.h>
#include <stdlib.h>
struct STUDENT {
	int Roll, Mark;
	char Name[32];
	struct STUDENT *link;
} *head, *temp, *ptr;
void insert_at_first() {
	temp = (struct STUDENT *)malloc(sizeof(struct STUDENT));
	temp->link = head->link;
	head->link = temp;
	printf("Enter Name : ");
	scanf("%s", temp->Name);
	printf("Enter Roll No : ");
	scanf("%d", &temp->Roll);
	printf("Enter Total-Mark : ");
	scanf("%d", &temp->Mark);
}
void insert() {
	if (head->link == NULL) {
		insert_at_first();
		return;
	}
	ptr = head->link;
	while (ptr->link != NULL) {
		ptr = ptr->link;
	}
	temp = (struct STUDENT *)malloc(sizeof(struct STUDENT));
	temp->link = NULL;
	ptr->link = temp;
	printf("Enter Name : ");
	scanf("%s", temp->Name);
	printf("Enter Roll No : ");
	scanf("%d", &temp->Roll);
	printf("Enter Total-Mark : ");
	scanf("%d", &temp->Mark);
}
void Display() {
	if (head->link == NULL) {
		printf("Empty List\n");
		return;
	}
	ptr = head->link;
	printf("Roll No: \t Name \t Total Mark\n");
	while (ptr != NULL) {
		printf("%d \t %s \t %d\n", ptr->Roll, ptr->Name, ptr->Mark);
		ptr = ptr->link;
	}
}
void Delete() {
	if (head->link == NULL) {
		printf("List is empty! Nothing to delete.\n");
		return;
	}

	printf("Enter Roll Number to delete : ");
	int num;
	scanf("%d", &num);

	ptr = head->link;
	temp = head;
	while (ptr != NULL && ptr->Roll != num) {
		temp = ptr;
		ptr = ptr->link;
	}
	if (ptr == NULL) {
		printf("Roll number %d is not in the list\n", num);
		return;
	}
	temp->link = ptr->link;
	printf(
		"Student %s with roll number %d and Mark : %d deleted successfully\n",
		ptr->Name, num, ptr->Mark);
	free(ptr);
}
int main() {
	head = (struct STUDENT *)malloc(sizeof(struct STUDENT));
	head->link = NULL;
	int choice;
	do {
		printf("Student Menu\n");
		printf("1.Dispaly\n");
		printf("2.Input\n");
		printf("3.Delete\n");
		printf("4.exit\n");
		printf("Enter choice : ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			Display();
			break;
		case 2:
			insert();
			Display();
			break;
		case 3:
			Delete();
			Display();
			break;
		case 4:
			ptr = head->link;
			while (ptr != NULL) {
				temp = ptr;
				ptr = ptr->link;
				free(temp);
			}
			free(head);
			printf("Exiting...\n");
			break;
		default:
			printf("invalid input");
			break;
		}
	} while (choice != 4);
	return 0;
}