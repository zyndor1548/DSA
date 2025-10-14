#include <stdio.h>
int main() {
	int t1[10][3] = {{2, 3, 3}, {0, 0, 1}, {0, 2, 5}, {1, 2, 2}};
	int t2[10][3] = {{2, 3, 2}, {0, 0, 1}, {1, 1, 1}};
	int t3[10][3];
	/*	printf("Enter number of columns : ");
		scanf("%d",&t1[0][0]);
		printf("Enter number of rows : ");
		scanf("%d",&t1[0][1]);
		t2[0][0] = t1[0][0];
		t2[0][1] = t1[0][1];
		printf("Enter number of non zero values in first tuple: ");
		scanf("%d",&t1[0][2]);
		t2[0][2] = t1[0][2];
		for(int i = 1;i <= t1[0][2];i++){
			printf("enter i of the %d non zero value : ",i);
			scanf("%d",&t1[i][0]);
			printf("enter i of the %d non zero value : ",i);
			scanf("%d",&t1[i][1]);
			printf("enter value : ");
			scanf("%d",&t1[i][2]);
		}
		printf("Enter number of non zero values in second tuple: ");
		scanf("%d",&t2[0][2]);
		for(int i = 1;i <= t2[0][2];i++){
			printf("enter i of the %d non zero value : ",i);
			scanf("%d",&t2[i][0]);
			printf("enter i of the %d non zero value : ",i);
			scanf("%d",&t2[i][1]);
			printf("enter value : ");
			scanf("%d",&t2[i][2]);
		}
	*/
	t3[0][0] = t1[0][0];
	t3[0][1] = t1[0][1];
	int k = 0;
	int a = 1, b = 1;
	int gl = ((t1[0][2] > t2[0][2]) ? t1[0][2] : t1[0][2]);
	// printf("gl %d\n",gl);
	for (int i = 1; i <= gl; i++) {
		// printf("iteration %d\n", i );
		// printf("a = %d,b = %d\n",a,b);
		if (t2[0][2] < i) {
			// printf("a\n");
			k++;
			t3[k][0] = t1[a][0];
			t3[k][1] = t1[a][1];
			t3[k][2] = t1[a][2];
			a++;
			continue;
		}
		if (t1[0][2] < i + 1) {
			// printf("b\n");
			k++;
			t3[k][0] = t2[b][0];
			t3[k][1] = t2[b][1];
			t3[k][2] = t2[b][2];
			b++;
			continue;
		}
		if (t1[a][0] == t2[a][1] && t1[a][0] == t2[a][1]) {
			// printf("a and b\n");
			k++;
			t3[k][0] = t1[a][0];
			t3[k][1] = t1[a][1];
			t3[k][2] = t1[a][2] + t2[b][2];
			a++;
			b++;
		} else {
			if (t1[a][1] < t2[b][1]) {
				// printf("a\n");
				k++;
				t3[k][0] = t1[a][0];
				t3[k][1] = t1[a][1];
				t3[k][2] = t1[a][2];
				a++;
			} else {
				// printf("b\n");
				k++;
				t3[k][0] = t2[b][0];
				t3[k][1] = t2[b][1];
				t3[k][2] = t2[b][2];
				b++;
			}
		}
		printf("lalala %d %d %d \n", t3[k][0], t3[k][1], t3[k][2]);
	}
	t3[0][2] = k;
	for (int i = 0; i <= t3[0][2]; i++) {
		printf("%d %d %d \n", t3[i][0], t3[i][1], t3[i][2]);
	}
	return 0;
}
