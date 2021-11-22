
#include <stdio.h>

int merge(int[], int, int, int);
int sort_merge(int[], int, int);
//void print(int[], int);

int count = 0;

int main()
{
    int i, n;
    int in_count = 0;
    int A[100000];
    scanf("%d ", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    in_count = sort_merge(A, 0, n - 1);
    /*
    print(A, n);
    printf("\n"); 
    */

    printf("%d", in_count);
    printf("\n");
    printf("%d", count);

    return 0;
}

int merge(int A[], int l, int mid, int r)
{
    int i, j, k;
    int sizeL = mid - l + 1;
    int sizeR = r - mid;
    int in_count = 0;
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
        count++;
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
            in_count += (sizeL - i);
        }
        k++;
    }
    while (i < sizeL)
    {
        count++;
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < sizeR)
    {
        count++;
        A[k] = R[j];
        j++;
        k++;
    }
    return in_count;
}

/* 
void print(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
} 
*/

int sort_merge(int A[], int l, int r)
{
    int in_count = 0;
    if (l < r)
    {

        int m = (l + r) / 2;

        in_count += sort_merge(A, l, m);
        in_count += sort_merge(A, m + 1, r);

        in_count += merge(A, l, m, r);
    }
    return in_count;
}
