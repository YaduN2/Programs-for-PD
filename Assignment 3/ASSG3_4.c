
#include <stdio.h>
void merge(int[], int, int, int);
void sort_merge(int[], int, int);
void print(int[], int);

int count = 0;

int main()
{
    int i, n;
    int A[100000];
    scanf("%d ", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    sort_merge(A, 0, n - 1);
    print(A, n);
    printf("\n");
    printf("%d", count);
    return 0;
}

void merge(int A[], int l, int mid, int r)
{

    int i, j, k;
    int sizeL = mid - l + 1;
    int sizeR = r - mid;

    int L[50000], R[50000];

    for (i = 0; i < sizeL; i++)
        L[i] = A[l + i];
    for (i = 0; i < sizeR; i++)
        R[i] = A[mid + 1 + i];

    i = 0;
    j = 0;
    k = l;
    while (i < sizeL && j < sizeR)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
            count++;
        }
        else
        {
            A[k] = R[j];
            j++;
            count++;
        }
        k++;
    }
    while (j < sizeR)
    {
        count++;
        A[k] = R[j];
        j++;
        k++;
    }
    while (i < sizeL)
    {
        count++;
        A[k] = L[i];
        i++;
        k++;
    }
}

void print(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
}

void sort_merge(int A[], int l, int r)
{

    if (l < r)
    {

        int mid = l + (r - l) / 2;

        sort_merge(A, l, mid);
        sort_merge(A, mid + 1, r);

        merge(A, l, mid, r);
    }
}
