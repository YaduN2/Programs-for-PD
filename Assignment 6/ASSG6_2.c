#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *node;
struct QUEUE
{
    node head, tail;
};
typedef struct QUEUE *QUEUE;

//change head and tail

node CREATE_NODE(int data)
{
    node temp;
    temp = (node)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int QUEUEEMPTY(QUEUE Q)
{
    if (Q->head == NULL)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

void ENQUEUE(QUEUE Q, int data)
{
    node new_node = CREATE_NODE(data);
    if (Q->head == NULL)
    {
        Q->head = new_node;
        Q->tail = new_node;
    }
    else
    {
        Q->tail->next = new_node;
        Q->tail = new_node;
    }
}

void DEQUEUE(QUEUE Q)
{
    if (QUEUEEMPTY(Q) == -1)
    {
        printf("-1\n");
        return;
    }
    else
    {
        node temp_node = Q->head;
        printf("%d\n", temp_node->data);
        if (Q->head == Q->tail)
        {
            Q->head = NULL;
            Q->tail = NULL;
        }
        else
        {
            Q->head = Q->head->next;
        }
        free(temp_node);
    }
}

void print_queue(QUEUE Q)
{
    node temp = Q->head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(void)
{
    QUEUE Q;
    Q = (QUEUE)malloc(sizeof(QUEUE));
    Q->head = NULL;
    Q->tail = NULL;
    int data;
    char choice;
    scanf("%c", &choice);
    while (choice != 't')
    {
        switch (choice)
        {
        case 'i':
            //printf("START PUSH!\n");
            scanf("%d", &data);
            ENQUEUE(Q, data);
            //printf("END PUSH!\n");
            break;

        case 'd':
            DEQUEUE(Q);
            break;

        case 'p':
            print_queue(Q);
            break;

        case 'e':
            if (QUEUEEMPTY(Q) == 1)
                printf("1\n");
            else
                printf("-1\n");
            break;

        default:
            break;
        }
        scanf("%c", &choice);
    }
    return 0;
}