#include <stdio.h>
void swap(int A[], int i, int j)
{
    //printf("!!!SWAPING %d and %d !!!\n", i, j);
    int temp;
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
int Lsearch(int A[], int size, int ele)
{
    int i;
    for (i = 1; i <= size; i++)
        if (ele == A[i])
            return i;
}
int min_heapify(int A[], int size, int i)
{
    int left = 2 * i, right = 2 * i + 1;
    int smallest;
    if (left <= size && A[left] < A[i])
    {
        smallest = left;
    }
    else
    {
        smallest = i;
    }
    if (right <= size && A[right] < A[smallest])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(A, i, smallest);
        min_heapify(A, size, smallest);
    }
}

void build_heap(int A[], int size)
{
    int i;
    if (size > 1)
    {
        for (i = (size / 2); i > 0; i--)
            min_heapify(A, size, i);
    }
}

void INSERT(int A[], int token, int size)
{
    int i;
    A[size] = token;
    build_heap(A, size);
}

void Extract_Next_Patient(int A[], int size)
{
    if (size < 1)
    {
        printf("-1\n");
        return;
    }
    printf("%d\n", A[1]);
    swap(A, 1, size);
    size -= 1;
    min_heapify(A, size, 1);
}
void Get_Next_Patient(int A[])
{
    printf("%d\n", A[1]);
}
void Display_Queue(int A[], int size)
{
    int i, save_size = size;
    for (i = 1; i <= save_size; i++)
    {
        printf("%d ", A[1]);
        swap(A, 1, size);
        size -= 1;
        min_heapify(A, size, 1);
    }
    build_heap(A, save_size);
    printf("\n");
}
void Change_Token_Number(int A[], int token, int x, int size)
{

    int index = Lsearch(A, size, token), i;
    /*     for (i = 1; i <= size; i++)
        printf("%d ", A[i]); */
    A[index] = x;
    while (index > 1 && A[index / 2] > A[index])
    {
        swap(A, index, (index / 2));
        index = index / 2;
    }
    /*     for (i = 1; i <= size; i++)
        printf("%d ", A[i]); */
}
void main()
{
    char choice;
    int A[10000];
    int x, token, size = 0;
    scanf("%c", &choice);
    while (choice != 's')
    {
        if (choice == 'i')
        {
            scanf("%d", &token);
            size += 1;
            INSERT(A, token, size);
        }
        if (choice == 'e')
        {
            Extract_Next_Patient(A, size);
            size -= 1;
        }
        if (choice == 'm')
        {
            Get_Next_Patient(A);
        }
        if (choice == 'd')
        {
            Display_Queue(A, size);
        }
        if (choice == 'c')
        {
            scanf("%d", &token);
            scanf("%d", &x);
            Change_Token_Number(A, token, x, size);
        }
        scanf("%c", &choice);
    }
}