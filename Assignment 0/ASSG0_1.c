#include<stdio.h>
int main()
{
    int num,num2,remainder  ;
    scanf("%d",&num);
    num2 = num;
    int rev = 0;
    if(num < 0)
    {
        printf("NO");
        return 0;
    }
    while(num2 != 0)
    {
        remainder = num2 % 10;
        rev = rev*10 + remainder;
        num2 = num2 / 10;
    }
    if(rev == num)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;

}
