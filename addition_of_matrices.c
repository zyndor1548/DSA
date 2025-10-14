#include <stdio.h>
int main(){
	int A[2][10][10],col,row;
	printf("Enter number of columns : ");
	scanf("%d",&col);
	printf("Enter number of rows : ");
	scanf("%d",&row);
	for(int i = 0;i<2;i++){
		for(int j = 0;j<col;j++){
			for(int k = 0;k<row;k++){
				printf("A[%d][%d][%d] : ",i,j,k);
				scanf("%d",&A[i][j][k]);
			}
		}
		printf("\n");
	}
	printf("added matrix = \n");
	for(int j = 0;j<col;j++){
		for(int k = 0;k<row;k++){
			printf("  %d  ",A[0][j][k] + A[1][j][k]);
		}
		printf("\n");
	}
	return 0;
}
