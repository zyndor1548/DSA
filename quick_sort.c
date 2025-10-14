#include <stdio.h>
int max, a[50];
void swap(int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
int partition(int low, int high) {
	int i = low, j = high, x = a[low];
	while (i < j) {
		while (a[i] <= x && i < max)
			i++;
		while (a[j] > x && j >= 0)
			j--;
		if (i < j)
			swap(i, j);
		else
			swap(j, low);
	}
	return j;
}
void quick(int low, int high) {
	if (low < high) {
		int mid = partition(low, high);
		quick(low, mid - 1);
		quick(mid + 1, high);
	}
}
int main() {
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
	quick(0, max - 1);
	printf("Sorted list : ");
	for (int i = 0; i < max; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 1;
}
