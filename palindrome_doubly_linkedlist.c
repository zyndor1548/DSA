#include <stdio.h>
#include <stdlib.h>

struct Node {
	char data;
	struct Node *blink, *flink;
} *head, *ptr, *temp;
void insert_at_first(char val) {
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->flink = head->flink;
	head->flink = temp;
	if (head->flink != NULL) {
		head->flink->blink = temp;
	}
	head->flink = temp;
	temp->data = val;
}
void insert(char val) {
	if (head->flink == NULL) {
		insert_at_first(val);
		return;
	}
	ptr = head->flink;
	while (ptr->flink != NULL) {
		ptr = ptr->flink;
	}
	temp = (struct Node *)malloc(sizeof(struct Node));
	ptr->flink = temp;
	temp->blink = ptr;
	temp->flink = NULL;
	temp->data = val;
}
void __exit() {
	ptr = head->flink;
	while (ptr != NULL) {
		temp = ptr->flink;
		free(ptr);
		ptr = temp;
	}
	free(head);
}
int IsPalindrome() {
	struct Node *start, *end;
	start = head->flink;
	if (start == NULL)
		return 0;
	end = start;
	while (end->flink != NULL) {
		end = end->flink;
	}
	while (start != end && start->blink != end) {
		if (start->data != end->data) {
			return 0;
		}
		start = start->flink;
		end = end->blink;
	}
	return 1;
}
int main() {
	head = (struct Node *)malloc(sizeof(struct Node));
	head->flink = NULL;
	head->blink = NULL;
	char str[512];
	printf("Enter string : ");
	scanf("%s", str);
	int i = 0;
	while (str[i] != '\0') {
		insert(str[i]);
		i++;
	}
	if (IsPalindrome() != 0) {
		printf("%s is a palindrome", str);
	} else {
		printf("%s is not a palindrome", str);
	}
	__exit();
	return 1;
}
