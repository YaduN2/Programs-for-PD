#include <stdio.h>
#include <stdlib.h>
struct node
{
    char key;
    struct node *next;
};
typedef struct node *node;

struct linkedlist
{
    struct node *head;
};
typedef struct linkedlist *linkedlist;

struct node *CREATE_NODE(char x)
{
    node temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->key = x;
    temp->next = NULL;
    return temp;
}

void LIST_INSERT_FRONT(linkedlist LList, node X)
{
    X->next = LList->head;
    LList->head = X;
}

struct node *LIST_SEARCH(linkedlist LList, char data)
{
    node temp = LList->head;
    while (temp != NULL)
    {
        if (temp->key == data)
            return temp;
        else
            temp = temp->next;
    }
    return NULL;
}

void LIST_INSERT_TAIL(linkedlist LList, node X)
{
    node temp = LList->head;
    if (temp != NULL)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = X;
    }
    else
    {
        LList->head = X;
    }
}

void PRINT_LIST(linkedlist LList)
{
    //printf("FUN>print_list!\n");
    node temp = LList->head;
    while (temp != NULL)
    {
        printf("%c ", temp->key);
        temp = temp->next;
    }
    printf("\n");
}

void LIST_INSERT_AFTER(linkedlist Llist, node insert_node, node after_node)
{
    insert_node->next = after_node->next;
    after_node->next = insert_node;
}

void LIST_INSERT_BEFORE(linkedlist Llist, node insert_node, node before_node)
{
    node prev, temp = Llist->head;
    prev = temp;
    if (temp == before_node)
    {
        insert_node->next = Llist->head;
        Llist->head = insert_node;
        return;
    }
    else
    {
        while (temp != before_node)
        {
            prev = temp;
            temp = temp->next;
        }
        LIST_INSERT_AFTER(Llist, insert_node, prev);
    }
}

void LIST_DELETE(linkedlist Llist, node delete_node)
{
    node prev, temp = Llist->head;
    prev = temp;
    if (temp == NULL)
    {
        printf("-1\n");
        return;
    }
    if (delete_node->next == NULL)
    {
        if (temp == delete_node)
        {
            printf("-2\n");
            Llist->head = NULL;
            free(delete_node);
            return;
        }
        while (temp->next != delete_node)
        {
            temp = temp->next;
        }
        printf("-2\n");
        temp->next = NULL;
        free(delete_node);
        return;
    }
    printf("%c\n", delete_node->next->key);
    if (temp == delete_node)
    {
        Llist->head = Llist->head->next;
        free(delete_node);
    }
    else
    {
        while (temp != delete_node)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = delete_node->next;
        free(delete_node);
    }
}

void LIST_DELETE_FRONT(linkedlist Llist)
{
    node temp = Llist->head;
    if (temp == NULL)
    {
        printf("-1\n");
        return;
    }
    printf("%c\n", temp->key);
    Llist->head = Llist->head->next;
    free(temp);
}

void LIST_DELETE_LAST(linkedlist Llist)
{
    /* node temp = Llist->head, prev;
    prev = temp;
    if (temp == NULL)
    {
        printf("-1\n");
        return;
    }
    else
    {
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        printf("%c\n", temp->key);
        if (prev != NULL)
        {
            prev->next = NULL;
        }
        else
        {
            Llist->head = NULL;
            temp = NULL;
        }
        free(temp);
        free(prev);
    } */

    node second_last = Llist->head;
    if (second_last == NULL)
    {
        printf("-1\n");
        return;
    }
    if (second_last->next == NULL)
    {
        printf("%c\n", second_last->key);
        second_last = NULL;
        Llist->head = NULL;
        return;
    }
    while (second_last->next->next != NULL)
    {
        second_last = second_last->next;
    }
    printf("%c\n", second_last->next->key);
    free(second_last->next);
    second_last->next = NULL;
}

int main(void)
{
    char x, key;
    char choice = 'a';
    linkedlist LList;
    LList = (linkedlist)malloc(sizeof(linkedlist));
    node temp_main, search_node;
    LList->head = NULL;
    while (choice != 'e')
    {
        scanf("%c", &choice);
        if (choice == 'f')
        {
            //printf("CREATE NODE\n");
            scanf("%s", &x);
            temp_main = CREATE_NODE(x);
            LIST_INSERT_FRONT(LList, temp_main);
            //printf("END f\n");
        }
        if (choice == 't')
        {
            //printf("CREATE NODE\n");
            scanf("%s", &x);
            temp_main = CREATE_NODE(x);
            LIST_INSERT_TAIL(LList, temp_main);
            //printf("END t\n");
        }
        if (choice == 'a')
        {
            //printf("CREATE NODE AFTER!\n");
            scanf("%s", &x);
            temp_main = CREATE_NODE(x);
            scanf("%s", &key);
            search_node = LIST_SEARCH(LList, key);
            if (search_node != NULL)
                LIST_INSERT_AFTER(LList, temp_main, search_node);
            //printf("\nEND a\n");
        }
        if (choice == 'b')
        {
            //printf("CREATE NODE BEFORE!\n");
            scanf("%s", &x);
            temp_main = CREATE_NODE(x);
            scanf("%s", &key);
            search_node = LIST_SEARCH(LList, key);
            if (search_node != NULL)
            {
                LIST_INSERT_BEFORE(LList, temp_main, search_node);
            }
        }
        if (choice == 'p')
        {
            //printf("PRINT LIST!\n");
            PRINT_LIST(LList);
            //printf("PRINT LIST END!\n");
        }
        if (choice == 'd')
        {
            scanf("%s", &key);
            search_node = LIST_SEARCH(LList, key);
            if (search_node != NULL)
            {
                LIST_DELETE(LList, search_node);
            }
            else
            {
                printf("-1\n");
            }
        }
        if (choice == 'i')
        {
            LIST_DELETE_FRONT(LList);
        }
        if (choice == 'l')
        {
            LIST_DELETE_LAST(LList);
        }
        /*         if (choice == 's')
        {
            printf("SEARCH LIST!\n");
            scanf("%d", &x);
            temp_main = search_list(LList, x);
            printf("%d %d", temp_main->key, temp_main->next);
            printf("\n");
        } */
        //printf("ENTER CHOICE!\n");
    }
}