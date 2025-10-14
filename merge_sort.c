#include <stdio.h>

int max, a[50], b[50];

void merge(int low, int mid, int high) {
	int i = low, j = mid + 1, k = low;
	while (i <= mid && j <= high) {
		if (a[i] <= a[j]) {
			b[k++] = a[i++];
		} else {
			b[k++] = a[j++];
		}
	}
	while (i <= mid) {
		b[k++] = a[i++];
	}
	while (j <= high) {
		b[k++] = a[j++];
	}
	for (int l = low; l <= high; l++) {
		a[l] = b[l];
	}
}

void mergesort(int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergesort(low, mid);
		mergesort(mid + 1, high);
		merge(low, mid, high);
	}
}

int main() {
	printf("Enter number of elements in the array: ");
	scanf("%d", &max);

	for (int i = 0; i < max; i++) {
		printf("Enter element %d: ", i);
		scanf("%d", &a[i]);
	}

	printf("Unsorted list: ");
	for (int i = 0; i < max; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	mergesort(0, max - 1);

	printf("Sorted list: ");
	for (int i = 0; i < max; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
