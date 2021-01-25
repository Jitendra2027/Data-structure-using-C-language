#include<stdio.h>
#include<stdlib.h>
void create();
void display();
struct node
{
    int data;
    struct node *next,*previous;
};
struct node *head=0,*temp;
int count=0;
int main()
{
    int i,choice;
    do
    {
        printf("Enter your choice:");
        printf("1.CREATE DOUBLY CIRCULAR LINK LIST\t 2.DISPLAY\t 3.EXIT\n");
        printf("Your choice is:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
                create();
                break;
        case 2:
                display();
                break;
        case 3:
                exit(1);
        default:
                printf("Please enter a valid choice...!\n");
        }
    }
    while(choice!=0);
    return 0;
}
void create()
{
    struct node *newnode;
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
        }
        else
        {
            temp->next=newnode;
            newnode->previous=temp;
            temp=newnode;
        }
        newnode->next=head;
        head->previous=newnode;
        count++;
        printf("Do you want to create more node->(1/0):");
        scanf("%d",&i);
    }while(i!=0);
    printf(" %d ",newnode->next->data);
}
void display()
{
    if(head==0)
        printf("Your list is empty...!\n");
    else
        {
                temp=head;
                printf("Your list is:");
                while(temp->next!=head)
                {
                    printf("%d ",temp->data);
                    temp=temp->next;
                }
                printf("%d",temp->data);
                printf("\nNumber of the node are the %d\n",count);
        }
}

