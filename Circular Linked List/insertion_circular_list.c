#include<stdio.h>
#include<stdlib.h>

void printList();
void createList();
void insertBeg();
void insertEnd();
void insertPos();

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
        printf("\t\t\t\t\t*****Enter your choice****\n");
        printf("1.INSERT AT BEGIN\t 2.INSERT AT END\t 3.INSERT AT POSITION\t 4.DISPLAY CIRCULAR LIST\t 5.EXIT\n");
        printf("Your choice is:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    insertBeg();
                    break;
            case 2:
                    insertEnd();
                    break;
            case 3:
                    insertPos();
                    break;
            case 4:
                    printList();
                    break;
            case 5:
                    exit(1);
            default:
                    printf("Please enter a valid choice...!\n");
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
void insertBeg()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(tail==0)
    {
        tail=newnode;
        tail->next=newnode;
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
    }
    count++;
    printf("Item inserted at begin successfully...!\n");
}
void insertEnd()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(tail==0)
    {
        tail=newnode;
        tail->next=newnode;
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
    count++;
    printf("Item inserted at end successfully...!\n");
}
void insertPos()
{
    int pos,i=1;
    printf("Enter the position:");
    scanf("%d",&pos);
    if(pos==1)
        insertBeg();
    else if(pos==(count+1))
        insertEnd();
    else if(pos<0 || pos>count+1)
        printf("Enter a valid position you have only %d nodes...!\n",count);
    else
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data:");
        scanf("%d",&newnode->data);
        newnode->next=0;
        temp=tail->next;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        count++;
        printf("Item inserted at %d position successfully...!\n",pos);
    }
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
