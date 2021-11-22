#include <stdio.h>

void swap(int A[], int a, int b)
{
    int temp;
    temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

int count = 1;

int max_heapify(int A[], int size, int i)
{
    int l = 2 * i, r = 2 * i + 1;
    int largest;
    if (l <= size && A[l] > A[i])
    {
        count += 1;
        largest = l;
    }
    else
    {
        count += 1;
        largest = i;
    }
    if (r <= size && A[r] > A[largest])
    {
        count += 1;
        largest = r;
    }
    if (largest != i)
    {
        swap(A, i, largest);
        max_heapify(A, size, largest);
    }
}

int Build_Max_Heap(int A[], int size)
{
    int i;
    for (int i = size / 2; i >= 1; i--)
        max_heapify(A, size, i);
}

int sort_heap(int A[], int size)
{
    int i;
    Build_Max_Heap(A, size);
    for (i = size; i > 1; i--)
    {
        swap(A, 1, i);
        size = size - 1;
        max_heapify(A, size, 1);
    }
}

void main()
{
    int A[100000];
    int n, i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    sort_heap(A, n);
    for (i = 1; i <= n; i++)
        printf("%d ", A[i]);
    printf("\n%d", count);
}