#include <stdio.h>
int main() {
	int A[10][10], T[10][3], col, row;
	printf("Enter number of columns : ");
	scanf("%d", &col);
	printf("Enter number of rows : ");
	scanf("%d", &row);
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			printf("A[%d][%d] : ", i, j);
			scanf("%d", &A[i][j]);
		}
	}
	printf("sparse matrix = \n");
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	int k = 0;
	T[0][0] = col;
	T[0][1] = row;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (A[i][j] != 0) {
				k++;
				T[k][0] = i;
				T[k][1] = j;
				T[k][2] = A[i][j];
			}
		}
	}
	T[0][2] = k;
	printf("tuple representation = \n");
	for (int i = 0; i <= k; i++) {
		printf("%d %d %d \n", T[i][0], T[i][1], T[i][2]);
	}
	return 0;
}
