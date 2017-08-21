#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void printlist(struct node* n)
{
    while(n != NULL)
    {
        printf("%d  ", n->data);
        n = n->next;
    }
    printf("\n");
}

void detectloop(struct node* head)
{
    struct node *slow = head;
    struct node *fast = head;
    while(slow && fast && fast->next){
        printf("\n inside loop\n");
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            printf("\n loop detected\n");
            break;
        }
    }
    printf("\n No loop in the list\n");
}

int main()
{
    struct node *first = NULL;
    struct node *second = NULL;
    struct node *third = NULL;
    struct node *fourth = NULL;
    struct node *fifth = NULL;

    first = (struct node*)malloc(sizeof(struct node*));
    second = (struct node*)malloc(sizeof(struct node*));
    third = (struct node*)malloc(sizeof(struct node*));
    fourth = (struct node*)malloc(sizeof(struct node*));
    fifth = (struct node*)malloc(sizeof(struct node*));

    first->data = 1;
    first->next = second;

    second->data = 2;
    second->next = NULL;

    //        third->data = 3;
    //third->next = NULL;
    //        third->next = fourth;

    //      fourth->data = 4;
    //     fourth->next = NULL;

    //fifth->data = 5;
    //fifth->next = NULL;

    //     printlist(first);

    detectloop(first);

    return 0;
}
