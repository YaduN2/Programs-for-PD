#include <stdio.h>
#include <string.h>
struct Amoeba
{
    char Amoeba_Name[20];
    int Amoeba_Size;
};

void swap(struct Amoeba A[], int i, int j)
{
    //printf("!!!SWAPING %d and %d !!!\n", i, j);
    struct Amoeba temp;
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int min_heapify(struct Amoeba A[], int size, int i)
{
    int left = 2 * i, right = 2 * i + 1;
    int smallest;
    if (left <= size && A[left].Amoeba_Size < A[i].Amoeba_Size)
    {
        smallest = left;
    }
    else
    {
        smallest = i;
    }
    if (right <= size && A[right].Amoeba_Size < A[smallest].Amoeba_Size)
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(A, i, smallest);
        min_heapify(A, size, smallest);
    }
}

void build_heap(struct Amoeba A[], int size)
{
    int i;
    if (size > 1)
    {
        for (i = (size / 2); i > 0; i--)
            min_heapify(A, size, i);
    }
}

struct Amoeba Read(struct Amoeba a)
{
    scanf("%s", a.Amoeba_Name);
    scanf("%d", &a.Amoeba_Size);
    return a;
}

void Insert(struct Amoeba W[], struct Amoeba a, int size)
{
    int i;
    strcpy(W[size].Amoeba_Name, a.Amoeba_Name);
    W[size].Amoeba_Size = a.Amoeba_Size;
    /*     printf("BEFORE!!!");

    for (i = 1; i <= size; i++)
    {
        printf("%s ", W[i].Amoeba_Name);
        printf("%d ", W[i].Amoeba_Size);
    }
    printf("\n"); */
    build_heap(W, size);
    /*     printf("AFTER!!!");

    for (i = 1; i <= size; i++)
    {
        printf("%s ", W[i].Amoeba_Name);
        printf("%d ", W[i].Amoeba_Size);
    }
    printf("\n"); */

    if (W[1].Amoeba_Size == W[3].Amoeba_Size)
    {
        if (strcmp(W[1].Amoeba_Name, W[3].Amoeba_Name) > 0)
        {
            swap(W, 1, 3);
        }
    }
    if (W[1].Amoeba_Size == W[2].Amoeba_Size)
    {
        if (strcmp(W[1].Amoeba_Name, W[2].Amoeba_Name) > 0)
        {
            swap(W, 1, 2);
        }
    }
    /*       for (i = 1; i <= size; i++)
    {
        printf("%s ", W[i].Amoeba_Name);
        printf("%d ", W[i].Amoeba_Size);
    } 
    printf("\n"); */
}
struct Amoeba COMBINE(struct Amoeba W[], int size)
{
    int i, j = size;
    struct Amoeba newAmoeba;
    for (i = 1; i < j; i++)
    {
        struct Amoeba temp[2];
        temp[0] = W[1];
        swap(W, 1, size);
        size -= 1;
        min_heapify(W, size, 1);

        temp[1] = W[1];
        swap(W, 1, size);
        size -= 1;
        min_heapify(W, size, 1);

        newAmoeba = temp[0];
        newAmoeba.Amoeba_Size += temp[1].Amoeba_Size;

        /*         printf("COMBINE!!!");
        printf("\n"); */
        printf("%s %s %d", temp[0].Amoeba_Name, temp[1].Amoeba_Name, newAmoeba.Amoeba_Size);
        printf("\n");
        size += 1;
        W[size] = newAmoeba;
        build_heap(W, size);
    }
    return newAmoeba;
} int main()
{
    struct Amoeba a;
    struct Amoeba W[10000];
    int i;
    int size;
    scanf("%d", &size);
    for (i = 1; i <= size; i++)
    {
        a = Read(a);
        Insert(W, a, i);
    }
    /*     printf("\nSTART COMBINE!\n"); */
    a = COMBINE(W, size);
    printf("%s %d", a.Amoeba_Name, a.Amoeba_Size);
    return 0;
}