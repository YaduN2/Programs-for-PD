#include <stdio.h>
void InsertionSortAs(int[], int); //function declaration
void InsertionSortDs(int[], int); // function declaration
void Print(int[], int);           // function declaration

/* Start of main function */

int main()
{
    int A[1000], A1[500], A2[500];
    int i, j;
    int n, k;
    int even_count = 0, odd_count = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    for (i = 0, k = 0; i < n; i += 2, k++)
    {
        A1[k] = A[i];
        even_count++;
    }

    for (i = 1, k = 0; i < n; i += 2, k++)
    {
        A2[k] = A[i];
        odd_count++;
    }
    InsertionSortAs(A1, even_count); //function call
    InsertionSortDs(A2, odd_count);  //function call

    Print(A1, even_count); //function call
    printf("\n");
    Print(A2, odd_count); //function call
    return 0;
}

/* The function below sorts the input array in non-decreasing order */

void InsertionSortAs(int A1[], int size) //function definition
{
    int i, j;
    int temp, index;
    for (i = 0; i < size - 1; i++)
    {
        temp = A1[i];
        index = i;
        for (j = i + 1; j < size; j++)
        {
            if (A1[j] < temp)
            {
                temp = A1[j];
                index = j;
            }
        }
        A1[index] = A1[i];
        A1[i] = temp;
    }
}

/* The function below sorts the input array in non-increasing order */

void InsertionSortDs(int A2[], int size) //function definition
{
    int i, j;
    int temp, index;
    for (i = 0; i < size - 1; i++)
    {
        temp = A2[i];
        index = i;
        for (j = i + 1; j < size; j++)
        {
            if (A2[j] > temp)
            {
                temp = A2[j];
                index = j;
            }
        }
        A2[index] = A2[i];
        A2[i] = temp;
    }
}

/* The function below prints the input array of given size*/

void Print(int X[], int size) //function definition
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", X[i]);
}