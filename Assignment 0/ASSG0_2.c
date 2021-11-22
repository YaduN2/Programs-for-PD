#include<stdio.h>
int PALINDROME(int);
int main()
{
    int i,A[20],n,count = 0;

    scanf("%d",&n);

    for(i=0; i < n; ++i)
        scanf("%d",&A[i]);
    i=0;
    while (i  < n)
    {
         count = count + PALINDROME(A[i]);
         i++;
    }
    printf("%d",count);
    return 0;
}

int PALINDROME(int x)
{
    int num2,remainder  ;
    num2 = x;
    int rev = 0;
    if(x < 0)
    {
        return 0;
    }
    while(num2 != 0)
    {
        remainder = num2 % 10;
        rev = rev*10 + remainder;
        num2 = num2 / 10;
    }
    if(rev == x)
    {
        return 1;

    }
    else
    {
        return 0;

    }
}
