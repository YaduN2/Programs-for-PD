#include <stdio.h>
#include <math.h>
int check_num(int);
void main()
{
    int A[10000];
    int n, i;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    for (i = 0; i < n; i++)
    {
        if (check_num(A[i]) == 1)
            printf("%d ", A[i]);
    }
}

int check_num(int x)
{
    int last, second_last, powerof10 = 10;
    int temp = x;
    int flag = 1;
    while (temp > 0)
    {
        last = temp % powerof10;

        temp = temp / 10;
        second_last = temp % powerof10;
        if (second_last == 0)
            break;

        if (last < second_last)
        {
            flag = 0;
            break;
        }
    }

    if (flag == 0)
        return 0;
    else
        return 1;
}