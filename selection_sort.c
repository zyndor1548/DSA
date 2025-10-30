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
	int min, loc;
	for (int i = 0; i < max; i++) {
		min = a[i];
		loc = i;
		for (int j = i; j < max; j++) {
			if (a[loc] > a[j]) {
				min = a[j];
				loc = j;
			}
		}
		if (min != a[i]) {
			a[loc] = a[i];
			a[i] = min;
		}
	}
	printf("Sorted list : ");
	for (int i = 0; i < max; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
