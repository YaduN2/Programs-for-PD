#include <stdio.h>
int search_binary(int[], int, int, int);
int count = 0;

int main()
{
    int n, i, ele;
    int A[1000000];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    scanf("%d", &ele);
    int index = search_binary(A, 0, n - 1, ele);
    printf("%d", index);
    printf("\n");
    if (index == -1)
        printf("%d", count - 1);
    else
        printf("%d", count - 2);
    return 0;
}

int search_binary(int A[], int low, int high, int ele)
{
    count++;
    if (low > high)
    {
        if (A[low] != ele)
            return -1;
        return low;
    }
    int mid = low + (high - low) / 2;
    if (A[mid] >= ele)
    {
        return search_binary(A, low, mid - 1, ele);
    }
    return search_binary(A, mid + 1, high, ele);
}