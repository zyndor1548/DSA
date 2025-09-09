#include <stdio.h>
int main()
{
    int array[50], size;
    printf("Enter the size of input array : ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("\nEnter %d element : ", i + 1);
        scanf("%d", &array[i]);
    }
    int min, loc;
    printf("initial array  :");
    for (int k = 0; k < size; k++)
    {
        printf("%d ", array[k]);
    }
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        min = array[i];
        loc = i;
        for (int j = i + 1; j < size; j++)
        {
            if (min > array[j])
            {
                min = array[j];
                loc = j;
            }
        }
        if (min != array[i])
        {
            array[loc] = array[i];
            array[i] = min;
        }
        printf("itreation %d : ", i + 1);
        for (int k = 0; k < size; k++)
        {
            printf("%d ", array[k]);
        }
        printf("\n");
    }
    return 1;
}