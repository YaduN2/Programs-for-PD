#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
        return -1;
    }
    else
    {
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

int POP(STACK S)
{
    node select_node = S->top;
    //printf("POPPED data=%d\n", S->top->data);
    S->top = S->top->next;
    int temp = select_node->data;
    free(select_node);
    return temp;
}

int EVALUATEPOSTFIX(char postfix[])
{
    STACK S;
    S = (STACK)malloc(sizeof(STACK));
    S->top = NULL;
    int i = 0;
    int num;
    //printf("%s\n", postfix);

    while (1)
    {
        if (postfix[i] == '\0')
            break;

        //printf("selected = %c!", postfix[i]);
        if (postfix[i] == ' ')
        {
            i++;
            continue;
        }
        if (isdigit(postfix[i]))
        {
            //printf("\n");
            num = 0;
            while (postfix[i] != ' ')
            {
                num = num * 10 + (postfix[i] - '0');
                //printf("%d", num);
                i++;
            }
            i--;
            //printf("\nnum=%d!\n", num);
            PUSH(S, num);
        }
        else
        {

            int t1, t2;
            t2 = POP(S);
            t1 = POP(S);
            switch (postfix[i])
            {
            case '+':
                PUSH(S, t1 + t2);
                break;
            case '-':
                PUSH(S, t1 - t2);
                break;
            case '*':
                PUSH(S, t1 * t2);
                break;
            case '/':
                PUSH(S, t1 / t2);
                break;
            default:
                break;
            }
        }
        /* 
        printf("PRINT STACK:\n");
        node temp = S->top;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n"); 
        */
        i++;
    }
    int result = POP(S);
    return result;
}
int main()
{
    char postfix[500];
    gets(postfix);
    printf("%d", EVALUATEPOSTFIX(postfix));
    return 0;
}