#include <stdio.h>
#include <string.h>
struct QUEUE
{
    int head, tail;
    char A[100000][20]; //SIZE TOO BIG
    int size;
};

int QUEUEFULL(struct QUEUE Q)
{
    if (((Q.head == 0) && Q.tail == (Q.size - 1)) || (Q.tail == (Q.head - 1) % (Q.size - 1)))
        return -1;
    else
        return 1;
}

int QUEUEEMPTY(struct QUEUE Q)
{
    if (Q.head == -1)
        return -1;
    else
        return 1;
}

struct QUEUE ENQUEUE(struct QUEUE Q, char string[])
{
    int temp;
    if (QUEUEFULL(Q) != 1)
    {
        printf("-1\n");
        return Q;
    }
    else
    {
        if (Q.head == -1)
        {
            Q.head = 0;
            Q.tail = 0;
            strcpy(Q.A[Q.tail], string);
        }
        else if ((Q.tail == Q.size - 1) && (Q.head != 0))
        {
            Q.tail = 0;
            strcpy(Q.A[Q.tail], string);
        }
        else
        {
            Q.tail++;
            strcpy(Q.A[Q.tail], string);
        }
    }
    //printf("!!!%d - %s!!!\n", Q.tail, Q.A[Q.tail]);
    return Q;
}

struct QUEUE
DEQUEUE(struct QUEUE Q)
{
    //char string[20];
    if (QUEUEEMPTY(Q) != 1)
    {
        printf("-1\n");
        return Q;
    }

    printf("%s\n", Q.A[Q.head]);

    if (Q.head == Q.tail)
    {
        Q.head = -1;
        Q.tail = -1;
    }
    else if (Q.head == Q.size - 1)
    {
        Q.head = 0;
    }
    else
    {
        Q.head++;
    }
    return Q;
}

int
main(void)

{
    int size;
    char string[20];
    char choice = '1';
    struct QUEUE Q;
    scanf("%d", &size);
    Q.size = size;
    Q.head = -1;
    Q.tail = -1;
    while (choice != 't')
    {
        scanf("%c", &choice);
        switch (choice)
        {
        case 'i':
            //printf("ENQUEUE!\n");
            scanf("%s", &string);
            Q = ENQUEUE(Q, string);
            break;

        case 'd':
            //printf("DEQUEUE!\n");
            Q = DEQUEUE(Q);
            break;

        case 'f':
            if (QUEUEFULL(Q) == -1)
                printf("-1\n");
            else
                printf("1\n");
            break;

        case 'e':
            if (QUEUEEMPTY(Q) == -1)
                printf("-1\n");
            else
                printf("1\n");
            break;

        default:
            break;
        }
    }
    return 0;
}