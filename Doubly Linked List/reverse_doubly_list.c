//Reverse of doubly link list means swap the pointer of a node i.e. next and previous
#include<stdio.h>
#include<stdlib.h>
void create();
void display();
struct node
{
    int data;
    struct node *next,*previous;
};
struct node *head=0,*temp,*tail;
int count=0;
int main()
{
    printf("First create and then reverse the doubly list:---\n");
    create();
    printf("Doubly link list before reverse:--->");
    display();
    printf("Doubly link list after reverse--->");
    reverse();
    display();
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
void reverse()
{
    struct node *current,*nextnode;
    current=head;
    while(current!=0)
    {
        nextnode=current->next;
        current->next=current->previous;
        current->previous=nextnode;
        current=nextnode;
    }
    current=head;
    head=tail;
    tail=current;
}
