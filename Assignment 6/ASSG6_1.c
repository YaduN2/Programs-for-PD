#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *node;
struct STACK
{
    node top;
};
typedef struct STACK *STACK;

node CREATE_NODE(int data)
{
    node temp;
    temp = (node)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int STACK_EMPTY(STACK S)
{
    if (S->top == NULL)
    {
        printf("-1\n"); //is empty
        return -1;
    }
    else
    {
        printf("1\n"); //not empty
        return 1;
    }
}

void PUSH(STACK S, int data)
{
    node new_node = CREATE_NODE(data);
    if (S->top == NULL)
    {
        S->top = new_node;
    }
    else
    {
        new_node->next = S->top;
        S->top = new_node;
    }
}

void POP(STACK S)
{
    if (S->top == NULL)
    {
        printf("-1\n");
        return;
    }
    else
    {
        node select_node = S->top;
        printf("%d\n", S->top->data);
        S->top = S->top->next;
        free(select_node);
    }
}

int main(void)
{
    STACK S;
    S = (STACK)malloc(sizeof(STACK));
    S->top = NULL;
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
            PUSH(S, data);
            //printf("END PUSH!\n");
            break;

        case 'd':
            POP(S);
            break;

        case 'e':
            STACK_EMPTY(S);
            break;

        default:
            break;
        }
        scanf("%c", &choice);
    }
    return 0;
}