#include <stdio.h>

struct poly {
	int co, exp;
} p1[10], p2[10], sum[20];
int size_of_a, size_of_b, size_of_sum;

int Sum() {
	int i = 0, j = 0, k = 0;
	while (i < size_of_a && j < size_of_b) {
		if (p1[i].exp > p2[j].exp) {
			sum[k] = p1[i];
			k++;
			i++;
		} else if (p1[i].exp < p2[j].exp) {
			sum[k] = p2[j];
			k++;
			j++;
		} else {
			sum[k].exp = p1[i].exp;
			sum[k].co = p1[i].co + p2[j].co;
			i++;
			j++;
			k++;
		}
	}
	while (i < size_of_a) {
		sum[k] = p1[i];
		k++;
		i++;
	}
	while (j < size_of_b) {
		sum[k] = p2[j];
		k++;
		j++;
	}
	return k;
}

int main() {
	printf("First Polynomial\n");
	printf("Enter number of non-zero elements: ");
	scanf("%d", &size_of_a);
	for (int i = 0; i < size_of_a; i++) {
		printf("Enter coefficient: ");
		scanf("%d", &p1[i].co);
		printf("Enter exponent: ");
		scanf("%d", &p1[i].exp);
	}
	printf("Second Polynomial\n");
	printf("Enter number of non-zero elements: ");
	scanf("%d", &size_of_b);
	for (int i = 0; i < size_of_b; i++) {
		printf("Enter coefficient: ");
		scanf("%d", &p2[i].co);
		printf("Enter exponent: ");
		scanf("%d", &p2[i].exp);
	}

	size_of_sum = Sum();

	printf("First Polynomial: ");
	int first = 1;
	for (int i = 0; i < size_of_a; i++) {
		if (p1[i].co == 0)
			continue;
		if (!first)
			printf(" + ");
		if (p1[i].exp == 0) {
			printf("%d", p1[i].co);
		} else {
			printf("%dx^%d", p1[i].co, p1[i].exp);
		}
		first = 0;
	}
	printf("\n");

	printf("Second Polynomial: ");
	for (int i = 0; i < size_of_b; i++) {
		if (p2[i].co == 0)
			continue;
		if (p2[i].exp == 0) {
			printf("%d", p2[i].co);
		} else {
			printf("%dx^%d", p2[i].co, p2[i].exp);
		}
		// Check if there are more non-zero terms ahead
		int hasMore = 0;
		for (int j = i + 1; j < size_of_b; j++) {
			if (p2[j].co != 0) {
				hasMore = 1;
				break;
			}
		}
		if (hasMore)
			printf(" + ");
	}
	printf("\n");

	printf("Sum of Polynomials: ");
	for (int i = 0; i < size_of_sum; i++) {
		if (sum[i].co == 0)
			continue;
		if (sum[i].exp == 0) {
			printf("%d", sum[i].co);
		} else {
			printf("%dx^%d", sum[i].co, sum[i].exp);
		}
		// Check if there are more non-zero terms ahead
		int hasMore = 0;
		for (int j = i + 1; j < size_of_sum; j++) {
			if (sum[j].co != 0) {
				hasMore = 1;
				break;
			}
		}
		if (hasMore)
			printf(" + ");
	}
	printf("\n");

	return 0;
}
