#include<stdio.h>
#include<stdlib.h>
void printList();
void createList();
void reverseList();
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*head=0,*temp;
int count=0;
int main()
{
    createList();
    printf("Linked list before reverse:");
    printList();
    reverseList();
    printf("Linked list after reverse:");
    printList();
    return 0;
}
void reverseList()
{
    struct node *current,*next,*previous;
    previous=0;
    next=current=head;
    while(next!=0)
    {
        next=current->next;
        current->next=previous;
        previous=current;
        current=next;
    }
    head=previous;
}
void createList()
{
    int i;
    do
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data:");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
            head=temp=newnode;
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        count++;
        printf("Do you want to create more node->(1/0):");
        scanf("%d",&i);
    }
    while(i!=0);
}
void printList()
{
    if(head==0)
        printf("Sorry, Your list is empty...!\n");
    else
    {
        temp=head;
        //printf("Your list is:");
        while(temp!=0)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
        printf("Number of the nodes in the linked list are:%d\n",count);
    }
}
