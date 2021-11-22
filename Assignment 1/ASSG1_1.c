#include <stdio.h>
#include <math.h>
int main()
{
    int num, res, temp, i = 0;
    scanf("%d", &num);
    while (num != 0)
    {
        temp = (num % 10) * (pow(8, i));
        num = num / 10;
        res = res + temp;
        i++;
    }
    printf("%d", res);
    return 0;
}