#include <stdio.h>

struct poly
{
    int co, exp;
};

int Isin(struct poly a[], int size, int expo);
int Input(struct poly a[]);
int Sum(struct poly a[], int size_of_a, struct poly b[], int size_of_b, struct poly sum[]);
void Display(struct poly a[], int size);

int main()
{
    struct poly p1[10], p2[10], sum[20];

    printf("First Polynomial\n");
    int size_of_a = Input(p1);

    printf("Second Polynomial\n");
    int size_of_b = Input(p2);

    printf("Sum of Polynomials:\n");
    int size_of_sum = Sum(p1, size_of_a, p2, size_of_b, sum);

    Display(sum, size_of_sum);

    return 0;
}

int Isin(struct poly a[], int size, int expo)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i].exp == expo)
        {
            printf("This exponent is already in the polynomial\n");
            return 0;
        }
    }
    return 1;
}

int Input(struct poly a[])
{
    int nonzero;
    printf("Enter number of non-zero elements: ");
    scanf("%d", &nonzero);
    for (int i = 0; i < nonzero; i++)
    {
        int expo, coef;
        do
        {
            printf("Enter exponent: ");
            scanf("%d", &expo);
        } while (!Isin(a, i, expo));

        printf("Enter coefficient: ");
        scanf("%d", &coef);

        a[i].exp = expo;
        a[i].co = coef;
        printf("\n");
    }
    return nonzero;
}

int Sum(struct poly a[], int size_of_a, struct poly b[], int size_of_b, struct poly sum[])
{
    int i = 0, j = 0, k = 0;
    while (i < size_of_a && j < size_of_b)
    {
        if (a[i].exp < b[j].exp)
        {
            sum[k++] = a[i++];
        }
        else if (a[i].exp > b[j].exp)
        {
            sum[k++] = b[j++];
        }
        else
        {
            sum[k].exp = a[i].exp;
            sum[k].co = a[i].co + b[j].co;
            i++;
            j++;
            k++;
        }
    }
    while (i < size_of_a)
    {
        sum[k++] = a[i++];
    }
    while (j < size_of_b)
    {
        sum[k++] = b[j++];
    }
    return k;
}

void Display(struct poly a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i].co == 0)
            continue;
        if (a[i].exp == 0)
        {
            printf("%d", a[i].co);
        }
        else if (i == size - 1 || (i == size - 2 && a[size - 1].co == 0))
        {
            printf("%dx^%d", a[i].co, a[i].exp);
        }
        else
        {
            printf("%dx^%d + ", a[i].co, a[i].exp);
        }
    }
    printf("\n");
}
