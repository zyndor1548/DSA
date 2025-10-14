#include <stdio.h>

struct poly {
	int co, exp;
};

int Input(struct poly a[]);
int Sum(struct poly a[], int size_of_a, struct poly b[], int size_of_b,
		struct poly sum[]);
void Display(struct poly a[], int size);

int main() {
	struct poly p1[10], p2[10], sum[20];
	printf("First Polynomial\n");
	int size_of_a = Input(p1);
	printf("Second Polynomial\n");
	int size_of_b = Input(p2);
	printf("Sum of Polynomials:\n");
	int size_of_sum = Sum(p1, size_of_a, p2, size_of_b, sum);
	Display(p1, size_of_a);
	Display(p2, size_of_b);
	Display(sum, size_of_sum);
	return 0;
}

int Input(struct poly a[]) {
	int nonzero;
	printf("Enter number of non-zero elements: ");
	scanf("%d", &nonzero);
	for (int i = 0; i < nonzero; i++) {
		int expo, coef;
		printf("Enter exponent: ");
		scanf("%d", &expo);
		printf("Enter coefficient: ");
		scanf("%d", &coef);
		a[i].exp = expo;
		a[i].co = coef;
	}
	return nonzero;
}

int Sum(struct poly a[], int size_of_a, struct poly b[], int size_of_b,
		struct poly sum[]) {
	int i = 0, j = 0, k = 0;
	while (i < size_of_a && j < size_of_b) {
		if (a[i].exp > b[j].exp) {
			sum[k].exp = a[i].exp;
			sum[k].co = a[i].co;
			k++;
			i++;
		} else if (a[i].exp < b[j].exp) {
			sum[k].exp = b[j].exp;
			sum[k].co = b[j].co;
			k++;
			j++;
		} else {
			sum[k].exp = a[i].exp;
			sum[k].co = a[i].co + b[j].co;
			i++;
			j++;
			k++;
		}
	}
	while (i < size_of_a) {
		sum[k] = a[i];
		k++;
		i++;
	}
	while (j < size_of_b) {
		sum[k] = b[j];
		k++;
		j++;
	}
	return k;
}

void Display(struct poly a[], int size) {
	for (int i = 0; i < size; i++) {
		if (a[i].co == 0)
			continue;
		if (a[i].exp == 0) {
			printf("%d", a[i].co);
		} else {
			printf("%dx^%d + ", a[i].co, a[i].exp);
		}
	}
	printf("\n");
}
