
#include <stdio.h>
int main()
{
    int n, count = 0, flag = 0;
    int i = 0, j, fst_ix;
    scanf("%d", &n); //scan size of array
    int A[10000], A_ND[10000];

    for (int i = 0; i < n; i++) //creating array
    {
        scanf("%d", &A[i]);
    }

    //printf("\nArray Before Removing Duplicates: ");
    //for (int i = 0; i < n; i++)
    //    printf("%d ", A[i]);

    for (i = 0; i < n; i++) //creating second array without duplicate elements
    {
        for (j = 0; j < count; j++)
        {
            if (A[i] == A_ND[j])
                break;
        }
        if (j == count)
        {
            A_ND[count] = A[i];
            count++;
        }
    }

    //printf("\nArray After  Removing Duplicates:");
    //for (int i = 0; i < count; i++)
    //    printf("%d ", A_ND[i]);
    //printf("\n");

    for (i = 0; i < n; i++) //counting and printing dup element index
    {
        count = 0;
        for (j = 0; j < n; j++)
        {
            if (A_ND[i] == A[j])
            {

                count = count + 1;
                if (count == 1)
                {
                    fst_ix = j;
                }
                if (count == 2)
                {
                    printf("%d %d ", A_ND[i], fst_ix);
                }
                if (count >= 2)
                {
                    printf("%d ", j);
                }
            }
        }
        if (count > 1)
        {
            printf("%d\n", count);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("-1");
    }
    return 0;
}

/* 
The code works fine on https://www.onlinegdb.com/online_c_compiler with the input array as 0 0 0 0 0 (here,size 5), however it has some problems when running using the VScode's gcc compiler, I was not able to identify the problem. 
*/