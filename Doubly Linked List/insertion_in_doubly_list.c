#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void insertBeg();
void insertEnd();
void insertPos();
struct node
{
    int data;
    struct node *next,*previous;
};
struct node *newnode,*head=0,*temp,*tail;//tail is pointer variable which points to the last node.
//if we do not tail pointer then we have to traverse whole list as done in singly linked list.
int count=0;
int main()
{
    int i,choice;
    printf("Before insertion operation first create the list:\n");
    create();
    do
    {
        printf("Enter your choice:");
        printf("1.INSERT AT BEGIN\t 2.INSERT AT END\t 3.INSERT AT POSITION\t 4.DISPLAY\t 5.EXIT\n");
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
                display();
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
//time complexity for insertion at beginning is o(1)
void insertBeg()
{
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data:");
        scanf("%d",&newnode->data);
        head->previous=newnode;
        newnode->next=head;
        newnode->previous=0;
        head=newnode;
        count++;
}
//time complexity is o(n) if we do not use tail pointer and o(1) if we use tail pointer.
void insertEnd()
{
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data:");
        scanf("%d",&newnode->data);
        tail->next=newnode;
        newnode->previous=tail;
        newnode->next=0;
        count++;
}
//time complexity depends upon the position i.e. o(n).
void insertPos()
{
    int pos,i=1;
    printf("Enter the position:");
    scanf("%d",&pos);
    if(pos<0 || pos-1>count)
        printf("Please enter a valid position you have only %d nodes...!\n");
    else if(pos==1)
        insertBeg();
    else if(pos==count+1)
        insertEnd();
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
        newnode->previous=temp;
        temp->next->previous=newnode;
        temp->next=newnode;
        count++;
    }
}
void create()
{
    int i;
    do
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data:");
        scanf("%d",&newnode->data);
        newnode->next=0;
        newnode->previous=0;
        if(head==0)
        {
            head=temp=newnode;
            tail=temp;
        }
        else
        {
            temp->next=newnode;
            newnode->previous=temp;
            temp=newnode;
            tail=temp;
        }
        count++;
        printf("Do you want to create more node->(1/0):");
        scanf("%d",&i);
    }while(i!=0);
}
//time complexity is o(n).
void display()
{
    if(head==0)
        printf("Your list is empty...!\n");
    else
        {
                temp=head;
                printf("Your list is:");
                while(temp!=0)
                {
                    printf("%d ",temp->data);
                    temp=temp->next;
                }
                printf("\nNumber of the node are the %d\n",count);
        }
}
