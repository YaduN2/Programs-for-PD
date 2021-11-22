#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node *node;
typedef struct TREE *TREE;
typedef struct STACK *STACK;
typedef struct node_STACK *node_STACK;

struct node
{
    char data;
    struct node *left;
    struct node *right;
};
struct TREE
{
    node root;
};

struct node_STACK
{
    struct node *node;
    struct node_STACK *next;
};

struct STACK
{
    node_STACK top;
};

node_STACK CREATE_NODE_STACK(node node)
{
    node_STACK temp;
    temp = (node_STACK)malloc(sizeof(node_STACK));
    temp->node = node;
    temp->next = NULL;
}

node CREATE_NODE_TREE(char data)
{
    node temp;
    temp = (node)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void PUSH(STACK S, node newNode)
{
    node_STACK new_node = CREATE_NODE_STACK(newNode);
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

node POP(STACK S)
{
    if (S->top == NULL)
    {
        return NULL;
    }
    else
    {
        node_STACK select_node = S->top;
        S->top = S->top->next;
        node temp;
        temp = select_node->node;
        free(select_node);
        return temp;
    }
}

node CONSTRUCT_TREE(char postfix[])
{

    int i;
    //printf(postfix);
    STACK S;
    S = (STACK)malloc(sizeof(STACK));
    S->top = NULL;
    for (i = 0;; i++)
    {
        //printf("selected = %c\n", postfix[i]);
        if (postfix[i] == '\0')
            break;

        node tree_node;
        tree_node = CREATE_NODE_TREE(postfix[i]);

        if (isalpha(postfix[i]))
        {
            PUSH(S, tree_node);
        }
        else
        {
            node top1, top2;
            top1 = POP(S);
            tree_node->right = top1;
            top2 = POP(S);
            tree_node->left = top2;
            PUSH(S, tree_node);
        }

        /*         printf("PRINT STACK:\n");
        node_STACK temp = S->top;
        while (temp != NULL)
        {
            printf("%c ", temp->node->data);
            temp = temp->next;
        }
        printf("\n"); */
    }

    /*     printf("LAST PRINT STACK:\n");
    node_STACK temp2 = S->top;
    while (temp2 != NULL)
    {
        printf("%c ", temp2->node->data);
        temp2 = temp2->next;
    }
    printf("\n"); */

    node root = POP(S);
    return root;
}

void PREORDER(node node)
{
    if (node == NULL)
        return;
    printf("%c", node->data);
    PREORDER(node->left);
    PREORDER(node->right);
}

void INORDER(node node)
{
    if (node == NULL)
        return;
    INORDER(node->left);
    printf("%c", node->data);
    INORDER(node->right);
}

void POSTORDER(node node)
{
    if (node == NULL)
        return;
    POSTORDER(node->left);
    POSTORDER(node->right);
    printf("%c", node->data);
}

int main()
{
    char postfix[500];
    TREE T;
    T = (TREE)malloc(sizeof(TREE));
    char choice = 'a';
    while (choice != 't')
    {
        scanf("%c", &choice);
        switch (choice)
        {
        case 'e':
            scanf("%s", postfix);
            T->root = CONSTRUCT_TREE(postfix);
            break;

        case 'i':
            INORDER(T->root);
            printf("\n");
            break;

        case 's':
            POSTORDER(T->root);
            printf("\n");
            break;

        case 'p':
            PREORDER(T->root);
            printf("\n");
            break;

        default:
            break;
        }
    }
    return 0;
}