#include <stdio.h>

int CONVERT(int);
int Circular_left_shift(int);
int Circular_right_shift(int);
int A[16];

int main()
{
    int n, i, k;
    scanf("%d", &n);
    scanf("%d", &k);
    for (i = 0; i < 16; i++)
    {
        A[i] = 0;
    }
    CONVERT(n); //fn. call
    for (i = 15; i >= 0; i--)
    {
        printf("%d", A[i]);
    }
    printf("\n");
    Circular_left_shift(k);  //fn. call
    Circular_right_shift(k); //fn. call

    return 0;
}

int CONVERT(int n) //fn. definition
{
    int i;
    for (i = 0; n > 0; i++)
    {
        A[i] = n % 2;
        n = n / 2;
    }
    return 0;
}

int Circular_left_shift(int k) //fn. definition
{
    int temp, i;

    int B[16];
    for (i = 0; i < 16; i++)
    {
        B[i] = A[i];
    }

    for (int j = 0; j < k; j++)
    {
        temp = B[15];
        for (i = 14; i >= 0; --i)
        {
            B[i + 1] = B[i];
        }
        B[0] = temp;
    }

    //printf("\nLEFT SHIFT!\n");
    for (i = 15; i >= 0; i--)
    {
        printf("%d", B[i]);
    }
    printf("\n");
}

int Circular_right_shift(int k) //fn. definition
{
    int temp, i;

    int B[16];
    for (i = 0; i < 16; i++)
    {
        B[i] = A[i];
    }

    for (int j = 0; j < k; j++)
    {
        temp = B[0];
        for (i = 1; i <= 15; i++)
        {
            B[i - 1] = B[i];
        }
        B[15] = temp;
    }

    //printf("\nRIGHT SHIFT!\n");
    for (i = 15; i >= 0; i--)
    {
        printf("%d", B[i]);
    }
    printf("\n");
}