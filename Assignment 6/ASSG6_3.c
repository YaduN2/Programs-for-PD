#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct node
{
    char data;
    struct node *next;
};
typedef struct node *node;

struct STACK
{
    node top;
};
typedef struct STACK *STACK;

node CREATE_NODE(char data)
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
        //printf("-1\n"); //is empty
        return -1;
    }
    else
    {
        //printf("1\n"); //not empty
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

    /*     printf("STACK:\n");
    node temp = S->top;
    while (temp != NULL)
    {
        printf("%c", temp->data);
        temp = temp->next;
    }
    printf("\n"); 
    */
}

char POP(STACK S)
{
    if (S->top == NULL)
    {
        //printf("-1\n");
        exit(0);
    }
    else
    {
        node select_node = S->top;
        //printf("%c\n", S->top->data);
        char x = S->top->data;
        S->top = S->top->next;
        free(select_node);
        return x;
    }
}

int getprecedence(char x)
{
    if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return 0;
}

bool is_operator(char x)
{
    if (x == '*' || x == '/' || x == '+' || x == '-')
        return true;
    else
        return false;
}

void INFIXTOPOSTFIX(char infix[])
{
    STACK S;
    S = (STACK)malloc(sizeof(STACK));
    S->top = NULL;
    PUSH(S, '(');
    strcat(infix, ")");

    int i, j;

    /*     
    printf("INFIX:\n");
    printf("%s", infix);
    printf("\n"); 
    */

    char postfix[1000];
    i = 0;
    j = 0;
    char selected = infix[i];

    while (selected != '\0')
    {
        //printf("selected: %c\n", selected);
        if (selected == '(')
        {
            PUSH(S, selected);
        }
        else if (isalnum(selected))
        {
            postfix[j] = selected;
            j++;
        }
        else if (is_operator(selected))
        {
            char top = POP(S);
            while (is_operator(top) && getprecedence(selected) <= getprecedence(top))
            {
                postfix[j] = top;
                j++;
                top = POP(S);
            }
            PUSH(S, top);
            PUSH(S, selected);
        }
        else if (selected == ')')
        {
            char top = POP(S);
            while (top != '(')
            {
                postfix[j] = top;
                j++;
                top = POP(S);
            }
        }
        i++;
        selected = infix[i];
        /*         
        printf("POSTFIX after i=%d \n", i);
        printf("%s\n", postfix); 
        */
    }
    postfix[j] = '\0';
    //printf("POSTFIX:\n");
    printf("%s", postfix);
    return postfix;
}

int main(void)
{
    char infix[1000];
    //scanf("%s", infix);
    gets(infix);
    INFIXTOPOSTFIX(infix);
    return 0;
}