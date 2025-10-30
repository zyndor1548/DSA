#include <stdio.h>
int main() {
	int max, a[50];
	printf("Enter number of elements in the array : ");
	scanf("%d", &max);
	for (int i = 0; i < max; i++) {
		printf("Enter %d element : ", i);
		scanf("%d", &a[i]);
	}

	printf("Unsorted list : ");
	for (int i = 0; i < max; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	int key;
	for (int i = 0; i < max - 1; i++) {
		key = a[i + 1];
		if (a[i] > key) {
			int j = i;
			while (a[j] > key && j != -1) {
				a[j + 1] = a[j];
				j -= 1;
			}
			a[j + 1] = key;
		}
	}
	printf("Sorted list : ");
	for (int i = 0; i < max; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
