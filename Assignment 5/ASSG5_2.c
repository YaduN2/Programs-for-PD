#include <stdio.h>
#include <stdlib.h>
struct node
{
    long int key;
    struct node *next, *prev;
};

struct DLList
{
    struct node *head;
};

typedef struct node *node;
typedef struct DLList *DLList;

struct node *CREATE_NODE(long int x)
{
    node temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->key = x;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

struct node *LIST_SEARCH(DLList DL, long int search_key)
{
    node temp = DL->head;
    while (temp != NULL)
    {
        if (temp->key == search_key)
            return temp;
        else
            temp = temp->next;
    }
    return NULL;
}

void LIST_INSERT_FRONT(DLList DL, node new_node)
{

    new_node->prev = NULL;
    new_node->next = DL->head;
    if (DL->head != NULL)
        DL->head->prev = new_node;
    DL->head = new_node;
}

void LIST_INSERT_TAIL(DLList DL, node new_node)
{
    node temp = DL->head;
    if (temp != NULL)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        new_node->prev = temp;
        temp->next = new_node;
    }
    else
    {
        DL->head = new_node;
    }
}

void PRINT_LIST(DLList DL)
{
    node temp = DL->head;
    while (temp != NULL)
    {
        printf("%ld ", temp->key);
        temp = temp->next;
    }
    printf("\n");
}

void LIST_INSERT_AFTER(DLList DL, node new_node, node after_node)
{
    if (after_node->next == NULL)
    {
        after_node->next = new_node;
        new_node->prev = after_node;
        return;
    }
    else
    {
        new_node->next = after_node->next;
        new_node->prev = after_node;
        after_node->next->prev = new_node;
        after_node->next = new_node;
    }
}

void LIST_INSERT_BEFORE(DLList DL, node new_node, node before_node)
{
    if (before_node->prev == NULL)
    {
        new_node->next = before_node;
        DL->head = new_node;
    }
    else
    {
        new_node->next = before_node;
        new_node->prev = before_node->prev;
        before_node->prev->next = new_node;
        before_node->prev = new_node;
    }
}

void LIST_DELETE_FIRST(DLList DL)
{
    node temp = DL->head;
    if (temp == NULL)
    {
        printf("-1\n");
        return;
    }
    if (temp->next == NULL)
    {
        printf("%ld\n", temp->key);
        DL->head = NULL;
        return;
    }
    printf("%ld\n", temp->key);
    DL->head = DL->head->next;
    DL->head->prev = NULL;
    free(temp);
}

void LIST_DELETE_LAST(DLList DL)
{
    node second_last = DL->head;
    if (second_last == NULL)
    {
        printf("-1\n");
        return;
    }
    if (second_last->next == NULL)
    {
        printf("%ld\n", second_last->key);
        second_last = NULL;
        DL->head = NULL;
        return;
    }
    while (second_last->next->next != NULL)
    {
        second_last = second_last->next;
    }
    printf("%ld\n", second_last->next->key);
    free(second_last->next);
    second_last->next = NULL;
}

void LIST_DELETE(DLList DL, node delete_node)
{

    if (delete_node->prev != NULL)
    {
        delete_node->prev->next = delete_node->next;
    }
    else
    {
        DL->head = delete_node->next;
    }
    if (delete_node->next != NULL)
    {
        printf("%ld\n", delete_node->next->key);
        delete_node->next->prev = delete_node->prev;
    }
    else
    {
        printf("NULL\n");
    }
    free(delete_node);
}

void PRINT_REVERSE(DLList DL, node search_node)
{
    node temp = search_node;
    while (temp != NULL)
    {
        printf("%ld ", temp->key);
        temp = temp->prev;
    }
    printf("\n");
}
int main(void)
{
    DLList DL;
    node temp_main, search_node;
    DL = (DLList)malloc(sizeof(DLList));
    DL->head = NULL;
    char choice = 'a';
    long int key, search_key;
    while (choice != 'e')
    {
        scanf("%c", &choice);
        switch (choice)
        {
        case 'f':
            //printf("INSERT FRONT\n");
            scanf("%ld", &key);
            temp_main = CREATE_NODE(key);
            LIST_INSERT_FRONT(DL, temp_main);
            //printf("INSERT FRONT END\n");
            break;

        case 't':
            //printf("INSERT TAIL\n");
            scanf("%ld", &key);
            temp_main = CREATE_NODE(key);
            LIST_INSERT_TAIL(DL, temp_main);
            //printf("INSERT TAIL END\n");
            break;

        case 'a':
            //printf("INSERT AFTER\n");
            scanf("%ld", &key);
            temp_main = CREATE_NODE(key);
            scanf("%ld", &search_key);
            search_node = LIST_SEARCH(DL, search_key);
            LIST_INSERT_AFTER(DL, temp_main, search_node);
            //printf("INSERT AFTER END\n");
            break;

        case 'b':
            //printf("INSERT BEFORE\n");
            scanf("%ld", &key);
            temp_main = CREATE_NODE(key);
            scanf("%ld", &search_key);
            search_node = LIST_SEARCH(DL, search_key);
            LIST_INSERT_BEFORE(DL, temp_main, search_node);
            //printf("INSERT BEFORE END\n");
            break;

        case 'p':
            //printf("PRINT LIST\n");
            PRINT_LIST(DL);
            //printf("PRINT LIST END\n");
            break;

        case 'd':
            scanf("%ld", &search_key);
            search_node = LIST_SEARCH(DL, search_key);
            if (search_node != NULL)
                LIST_DELETE(DL, search_node);
            else
                printf("Not Found\n");

            break;

        case 'i':
            LIST_DELETE_FIRST(DL);
            break;

        case 'l':
            LIST_DELETE_LAST(DL);
            break;
        case 'r':
            scanf("%ld", &search_key);
            search_node = LIST_SEARCH(DL, search_key);
            if (search_node != NULL)
                PRINT_REVERSE(DL, search_node);
            else
                printf("Not Found\n");
            break;
        default:
            break;
        }
    }
    return 0;
}
