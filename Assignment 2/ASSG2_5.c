#include <stdio.h>
void In_sort(int[], int);
void main()
{
    int A[1000];
    int n, m, i, k;
    int min = 0, max = 0;
    scanf("%d", &n);
    scanf("%d", &m);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    In_sort(A, n);
    for (i = 0; i < n - m; i++)
    {
        min = min + A[i];
    }
    for (i = 0, k = n - 1; i < n - m; i++, k--)
    {
        max = max + A[k];
    }
    int v = (max - min);
    printf("%d ", v);
}

void In_sort(int X[], int size)
{
    int i, j;
    int temp, index;
    for (i = 0; i < size - 1; i++)
    {
        temp = X[i];
        index = i;
        for (j = i + 1; j < size; j++)
        {
            if (X[j] < temp)
            {
                temp = X[j];
                index = j;
            }
        }
        X[index] = X[i];
        X[i] = temp;
    }
}
