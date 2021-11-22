#include <stdio.h>
int count = 0;
int search_binary(int[], int, int, int);

void main()
{
    int n, i, ele;
    int A[100000];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    scanf("%d", &ele);
    int index = search_binary(A, ele, 0, n - 1);
    printf("%d", index);
    printf("\n");
    printf("%d", count);
}

int search_binary(int A[], int ele, int first, int last)
{
    if (first <= last)
    {
        int mid = first + (last - 1) / 2;
        count++;
        if (A[mid] == ele)
            return mid;
        if (A[mid] < ele)
            return search_binary(A, ele, mid + 1, last);
        if (A[mid] > ele)
            return search_binary(A, ele, first, mid - 1);
    }
    return -1;
}