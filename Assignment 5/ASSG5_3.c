#include <stdio.h>
struct STACK
{
    int top;
    char A[100000];
    int size;
};

int STACK_EMPTY(struct STACK S)
{
    if (S.top == -1)
        return -1; // is empty
    else
        return 1;
}

int STACK_FULL(struct STACK S)
{
    if (S.top == S.size - 1)
        return -1; //is full
    else
        return 1;
}

struct STACK PUSH(struct STACK S, char c)
{
    int temp = S.top;
    if (STACK_FULL(S) != 1)
    {
        printf("-1\n");
        return S;
    }
    else
    {
        temp++;
        S.A[temp] = c;
        S.top = temp;
        char x = S.A[S.top];
    }
    return S;
}

struct STACK
POP(struct STACK S)
{
    int temp = S.top;
    if (STACK_EMPTY(S) != 1)
    {
        printf("-1\n");
        return S;
    }
    else
    {
        char x = S.A[temp];
        printf("%c\n", x);
        temp--;
        S.top = temp;
    }
    return S;
}

char
PEEK(struct STACK S)
{
    int temp = S.top;
    char x;
    x = S.A[temp];
    return x;
}

void print(struct STACK S)
{
    for (int i = S.top; i > -1; i--)
    {
        printf("%c ", S.A[i]);
    }
}

int main(void)

{
    char choice, x;
    int size;
    struct STACK S = {-1};
    scanf("%d", &size);
    S.size = size;
    //printf("size =%d\n", S.size);
    //rintf("top =%d\n", S.top);

    while (choice != 't')
    {
        scanf("%c", &choice);
        switch (choice)
        {
        case 'i':
            //printf("START PUSH\n");
            scanf("%s", &x);
            S = PUSH(S, x);
            break;

        case 'd':
            //printf("START POP\n");
            S = POP(S);
            break;

        case 'p':
            //printf("START PEEK\n");
            if (STACK_EMPTY(S) != 1)
                printf("-1\n");
            else
                printf("%c\n", PEEK(S));
            break;

        case 'P':
            //printf("START PRINT!\n");
            print(S);
            break;

        default:
            break;
        }
    }
    return 0;
}