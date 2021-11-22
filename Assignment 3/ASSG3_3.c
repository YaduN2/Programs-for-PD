#include <stdio.h>

int search_binary(int A[], int ele, int first, int last)
{
    if (first <= last)
    {
        int mid = first + (last - 1) / 2;
        if (A[mid] == ele)
            return mid;
        if (A[mid] > ele)
            return search_binary(A, ele, mid + 1, last);
        //if (A[mid] < ele)
        return search_binary(A, ele, first, mid - 1);
    }
    return -1;
}
int main()
{
    int n, m, i, ele, flag = 0;
    int A[1000000], B[1000000];
    int index;
    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    for (i = 0; i < m; i++)
        scanf("%d", &B[i]);

    i = 0;
    while (i < n)
    {
        ele = A[i];
        int index = search_binary(B, ele, 0, m - 1);
        if (index != -1)
        {
            flag = 1;
            printf("%d ", ele);
        }
        i++;
        continue;
    }
    if (flag == 0)
    {
        printf("-1");
    }
    return 0;
}