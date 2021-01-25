#include<stdio.h>
#include<stdlib.h>
void deleteBeg();
void deleteEnd();
void deletePos();
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
    printf("---Before deletion operation first create the list---\n");
    createList();
    printf("***Now perform insertion operation***\n");
    do
    {
        printf("Enter your choice:");
        printf("1.DELETE FROM BEGIN\t 2.DELETE FROM END\t 3.DELETE FROM POSITION\t 4.DISPLAY LIST\t 5.EXIT\n");
        printf("Your choice is:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    deleteBeg();
                    break;
            case 2:
                    deleteEnd();
                    break;
            case 3:
                    deletePos();
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
void deleteBeg()
{
    if(count==0 || head==0)
        printf("Your list is empty so deletion can't be performed.\n");
    else
    {
        temp=head;
        head=head->next;
        free(temp);
        count--;
        printf("Node deleted successfully from beginning...\n");
    }
}
void deleteEnd()
{
    struct node *previous;
    if(head==0)
        printf("Your is empty deletion can't be performed.\n");
    else
    {
        temp=head;
        while(temp->next!=0)
        {
            previous=temp;
            temp=temp->next;
        }
        previous->next=0;
        free(temp);
        count--;
        printf("Node deleted from end successfully...\n");
    }
}
void deletePos()
{
    int pos,i=1;
    if(head==0)
    {
        printf("Your list is empty deletion can't be performed.\n");
    }
    else
    {
        struct node *previous;
        printf("Enter the position:");
        scanf("%d",&pos);
        temp=head;
        if(pos-1>count || pos<0)
            printf("Enter a valid position ,list has only %d nodes.\n",count);
        else
        {
            while(i<pos)
            {
                previous=temp;
                temp=temp->next;
                i++;
            }
            previous->next=temp->next;
            free(temp);
            count--;
            printf("Node deleted from position %d successfully...\n",pos);
        }
    }
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
