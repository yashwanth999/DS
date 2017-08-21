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

void rev_list(struct node** head_ref)
{
struct node* prev =NULL;
struct node* current = *head_ref;
struct node* next = NULL;

while(current != NULL)
{
next = current->next;
current->next = prev;
prev = current;
current = next;
}

*head_ref =prev;
}

int main()
{
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;
    struct node *fourth = NULL;
    struct node *fifth = NULL;
    struct node *sixth = NULL;
    struct node *seven = NULL;



    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));
    fifth = (struct node*)malloc(sizeof(struct node));
    sixth = (struct node*)malloc(sizeof(struct node));
    seven = (struct node*)malloc(sizeof(struct node));

    head->data = 5;
    head->next = second;

    second->data = 10;
    second->next =third;

    third->data = 20;
    third->next =fourth;

    fourth->data = 25;
    fourth->next =fifth;

    fifth->data = 30;
    fifth->next =sixth;

    sixth->data = 35;
    sixth->next =seven;

    seven->data = 40;
    seven->next =NULL;


    printlist(head);

    rev_list(&head);

    printlist(head);
}
