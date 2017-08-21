#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void printlist(struct node* n)
{
    printf("\nlist is\n");
    while(n != NULL)
    {
        printf("%d\t", n->data);
        n = n->next;
    }
    printf("\n");
}

void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = *head_ref;

    *head_ref = new_node;
}

void insertafter(struct node* prev, int new_data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = prev->next;
    prev->next = new_node;
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
}

void delpos(struct node**  head_ref, int pos)
{
    struct node* temp = *head_ref;

    if (pos == 0)
    {
        *head_ref =temp->next;
        free(temp);
    }

    int i;
    for(i=0; i<pos-1 && temp!=NULL; i++)
    {
        temp = temp->next;
    }

    struct node* next = temp->next->next;

    free(temp->next);

    temp->next = next;
}

void deletekey(struct node** head_ref, int key)
{
    struct node* temp = *head_ref, *prev;

    if(temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
    }

    while(temp != NULL && temp->data != key)
    {
        prev =temp;
        temp =temp->next;
    }

    prev->next = temp->next;
    free(temp);
}

int main()
{
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data = 5;
    head->next = second;

    second->data = 10;
    second->next =third;

    third->data = 20;
    third->next =NULL;

    printlist(head);

    push(&head,0);

    printlist(head);

    insertafter(second,15);

    printlist(head);

    append(&head,25);

    printlist(head);

    deletekey(&head,20);

    printlist(head);

    delpos(&head,1);

    printlist(head);
}
