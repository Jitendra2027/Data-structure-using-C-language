#include<stdio.h>
#include<stdlib.h>
void insertAtBeg();
void insertAtEnd();
void insertAtPos();
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
    printf("---Before insertion operation first create the list---\n");
    createList();
    printf("***Now perform insertion operation***\n");
    do
    {
        printf("Enter your choice:");
        printf("1.INSERT AT BEGIN\t 2.INSERT AT END\t 3.INSERT AT POSITION\t 4.DISPLAY LIST\t 5.EXIT\n");
        printf("Your choice is:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    insertAtBeg();
                    break;
            case 2:
                    insertAtEnd();
                    break;
            case 3:
                    insertAtPos();
                    break;
            case 4:
                    printList();
                    break;
            case 5:
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
void insertAtBeg()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    count++;
}
void insertAtEnd()
{
    temp=head;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&newnode->data);
    newnode->next=0;
    while(temp->next!=0)
        temp=temp->next;
    temp->next=newnode;
    count++;
}
void insertAtPos()
{
    int pos,i=1;
    printf("Enter the position:");
    scanf("%d",&pos);
    if(pos-1>count || pos<0)
        printf("Enter a valid position for the node,you have only %d nodes\n",count);
    else if(pos==1)
        insertAtBeg();
    else if(pos==count)
        insertAtEnd();
    else
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data:");
        scanf("%d",&newnode->data);
        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        count++;
    }
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

