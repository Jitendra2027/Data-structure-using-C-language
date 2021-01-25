//Here we will only maintain a tail pointer and create a circular link list without head pointer.
//In this program tail->next will always contain the address of the first node.
#include<stdio.h>
#include<stdlib.h>

void printList();
void createList();

struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*tail=0,*temp;
int count=0;
int main()
{
    int choice;
    do
    {
        printf("Enter your choice:");
        printf("1.CREATE CIRCULAT LIST\t 2.DISPLAY CIRCULAT LIST\t 3.EXIT\n");
        printf("Your choice is:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    createList();
                    break;
            case 2:
                    printList();
                    break;
            case 3:
                    exit(1);
            default:
                    printf("Please enter a valid choice.");
        }
    }
    while(choice!=0);
    return 0;
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
        if(tail==0)
        {
            tail=newnode;
            newnode->next=tail;
        }
        else
        {
            newnode->next=tail->next;//tail->neat always contain the address of the first node
            tail->next=newnode;
            tail=newnode;
        }
        //last node address pointer contains the address of the first node
        //and make the list circular.
        count++;
        printf("Do you want to create more node->(1/0):");
        scanf("%d",&i);
    }
    while(i!=0);
}
void printList()
{
    if(tail==0)
        printf("Sorry, Your list is empty...!\n");
    else
    {
        temp=tail->next;//temp is initialized with first node address
        printf("Your list is:");
        while(temp->next!=tail->next)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
        printf("\n");
        printf("Number of the nodes in the linked list are:%d\n",count);
    }
}
