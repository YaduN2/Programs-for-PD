#include <stdio.h>
int merge_And_dup(int, int);
int sep_array_AND_print(int, int);

int A[10000], B[10000], AB[20000], AB_ND[20000]; // A & B are the input arrays, AB is combination of A&B, AB_ND is A&B without duplicate elements
int ND_count = 0;                                //count of non-duplicate elements
int i, n, m, j, k, count;

int main()
{
    scanf("%d", &n); //size of A
    scanf("%d", &m); //size of B
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    for (i = 0; i < m; i++)
        scanf("%d", &B[i]);

    merge_And_dup(n, m);
    sep_array_AND_print(n, m);
    return 0;
}

int merge_And_dup(int n, int m)
{

    int i, j, count = 0;
    for (i = 0; i < n; i++)
    {
        AB[i] = A[i];
    }
    for (i = 0, j = n; j < n + m && i < m; i++, j++)
    {
        AB[j] = B[i];
    }

    for (i = 0; i < n + m; i++) //creating array without duplicate elements
    {
        for (j = 0; j < count; j++)
        {
            if (AB[i] == AB_ND[j])
                break;
        }
        if (j == count)
        {
            ND_count++;
            AB_ND[count] = AB[i];
            count++;
        }
    }
    return 0;
}
int sep_array_AND_print(int n, int m)
{
    for (i = 0; i < ND_count; i++)
    {
        count = 0;
        for (j = 0; j < n + m; j++)
        {
            if (AB[j] == AB_ND[i])
                count++;
        }
        if (count > 1)
        {
            for (k = 0; k < count; k++)
            {
                printf("%d ", AB_ND[i]);
            }
        }
    }
    for (i = 0; i < ND_count; i++)
    {
        count = 0;
        for (j = 0; j < n + m; j++)
        {
            if (AB[j] == AB_ND[i])
                count++;
        }
        if (count == 1)
        {
            for (k = 0; k < count; k++)
            {
                printf("%d ", AB_ND[i]);
            }
        }
    }
    return 0;
}