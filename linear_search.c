#include <stdio.h>
int max, a[50];
int linearsearch(int key) {
	for (int i = 0; i < max; i++) {
		if (key == a[i])
			return i;
	}
	return -1;
}
int main() {
	printf("Enter number of elements in the array : ");
	scanf("%d", &max);
	for (int i = 0; i < max; i++) {
		printf("Enter %d element : ", i);
		scanf("%d", &a[i]);
	}
	int key;
	printf("\n\nEnter element to search : ");
	scanf("%d", &key);
	int returnval = linearsearch(key);
	if (returnval == -1)
		printf("element %d not found ", key);
	else
		printf("element %d found at index %d", key, returnval);
	printf("\n");
	return 0;
}
