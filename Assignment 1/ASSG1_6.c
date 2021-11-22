#include <stdio.h>
int num1, num2;

int GCD(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    else
    {
        GCD(y, x % y);
    }
}
int main()
{
    scanf("%d", &num1);
    scanf("%d", &num2);

    if (num1 == 0 && num2 == 0)
        return 0;
    int gcd = GCD(num1, num2);

    if (gcd < 0)
    {
        gcd = gcd * -1;
    }
    printf("%d", gcd);
    return 0;
}
