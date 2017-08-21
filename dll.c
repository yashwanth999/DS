#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

void printlist(struct node* n)
{
    struct node *last;
    while(n != NULL)
    {
        printf("%d\t",n->data);
        last = n;
        n = n->next;
    }
    while(last != NULL)
    {
        last = last->prev;
    }
    printf("\n");
}

void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = *head_ref;
    new_node->prev = NULL;

    if(*head_ref != NULL)
    {
        (*head_ref)->prev = new_node;
    }
    *head_ref = new_node;
}

void insertafter(struct node* prev, int new_data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = prev->next;

    prev->next = new_node;
    new_node->prev = prev;

    if(new_node->next != NULL)
    {
        new_node->next->prev = new_node;
    }
}


void append(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = NULL;

    struct node* last = *head_ref;

    while(last->next != NULL)
    {

        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

void delkey(struct node** head_ref,struct node *del)
{
    if(*head_ref == del){
        *head_ref = del->next;
    }

    if(del->next != NULL){
        del->next->prev = del->prev;
    }

    if(del->prev != NULL){
        del->prev->next = del->next;
    }
    free(del);

    return ;
}

int main()
{
    struct node *head = NULL;
    struct node *first = NULL;
    struct node *second = NULL;
    struct node *third = NULL;

    head = (struct node*)malloc(sizeof(struct node));
    first = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));


    head->data = 1;
    head->next = first;
    head->prev = NULL;

    first->data = 2;
    first->next = second;
    first->prev = head;

    second->data = 3;
    second->next = third;
    second->prev = first;

    third->data = 4;
    third->next = NULL;
    third->prev = second;

    printlist(head);

    push(&head,0);

    printlist(head);

    insertafter(first,1);

    printlist(head);

    append(&head,5);

    printlist(head);

    delkey(&head,first);

    return 0;
}
