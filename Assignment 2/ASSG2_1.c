#include <stdio.h>
int find_sum(int[], int);
void main()
{
    int A[100];
    int n, i, temp, sum;
    int count = 0, flag = 0;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    temp = A[0];
    for (i = 0; i < n; i++)
    {
        if (A[i] < 0)
            flag++;
        if (A[i] >= 0)
            count++;
        if (A[i] > temp)
            temp = A[i];
    }

    if (flag == n)
    {
        sum = temp;
        count = 1;
    }
    else
    {
        sum = find_sum(A, n);
    }
    printf("%d %d", sum, count);
}

int find_sum(int A[], int size)
{
    int i;
    int sum = 0;

    for (i = 0; i < size; i++)
    {
        if (A[i] > 0)
        {
            sum = sum + A[i];
        }
    }
    return sum;
}
