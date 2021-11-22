#include <stdio.h>
struct students
{
    int student_id;
    char student_name[50];
    int rank;
};
void swap(struct students A[], int i, int j)
{
    //printf("!!!SWAPING %d and %d !!!\n", i, j);
    struct students temp;
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int min_heapify(struct students A[], int size, int i)
{
    int left = 2 * i, right = 2 * i + 1;
    int smallest;
    if (left <= size && A[left].rank < A[i].rank)
    {
        smallest = left;
    }
    else
    {
        smallest = i;
    }
    if (right <= size && A[right].rank < A[smallest].rank)
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(A, i, smallest);
        min_heapify(A, size, smallest);
    }
}

void build_heap(struct students A[], int size)
{
    int i;
    if (size > 1)
    {
        for (i = (size / 2); i > 0; i--)
            min_heapify(A, size, i);
    }
}

void ENTER(struct students A[], int size)
{
    int i;
    scanf("%d", &A[size].student_id);
    scanf("%s", &A[size].student_name);
    scanf("%d", &A[size].rank);
    build_heap(A, size);
}

void INTERVIEW(struct students A[], int size)
{
    if (size < 1)
    {
        printf("-1");
        printf("\n");
        return;
    }
    printf("%d %s", A[1].student_id, A[1].student_name);
    printf("\n");

    swap(A, 1, size);
    size -= 1;
    min_heapify(A, size, 1);
}

void LIST(struct students A[], int size)
{
    if (size < 1)
    {
        printf("-1");
        printf("\n");

        return;
    }
    int i;
    struct students temp[10000];
    for (i = 1; i <= size; i++)
    {
        temp[i] = A[i];
    }
    build_heap(temp, size);
    int size_save = size;
    for (i = 1; i <= size_save; i++)
    {
        printf("%d ", temp[1].student_id);
        swap(temp, 1, size);
        size -= 1;
        min_heapify(temp, size, 1);
    }
    printf("\n");
}
void main()
{
    struct students A[10000];
    int n = 0, i;
    char choice;
    scanf("%c", &choice);
    while (choice != 't')
    {
        if (choice == 'e')
        {
            n += 1;
            //printf("choice e(n) =%d\n", n);
            ENTER(A, n);
        }
        if (choice == 'i')
        {
            INTERVIEW(A, n);
            n -= 1;
        }
        if (choice == 'l')
        {
            LIST(A, n);
        }
        scanf("%c", &choice);
    }
}