#include<stdio.h>
#include<stdlib.h>

void printList();
void createList();

struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*head=0,*temp;
int count=0;
int main()
{
    int choice;
    do
    {
        printf("Enter your choice:");
        printf("1.CREATE LIST\t 2.DISPLAY LIST\t 3.EXIT\n");
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
        printf("Your list is:");
        while(temp!=0)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
        printf("Number of the nodes in the linked list are:%d\n",count);
    }
}
