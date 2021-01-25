#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void frontOperation();
void rearOperation();
void display();

struct node
{
    int data;
    struct node *next;
};
struct node *front=0,*rear=0;
int count=0;
int main()
{
    int choice;
    do
    {
        printf("Enter your choice:");;
        printf("1.ENQUEUE\t 2.DEQUEUE\t 3.FRONT\t 4.REAR\t 5.DISPLAY\t 6.EXIT\n");
        printf("Your choice is:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
                enqueue();
                break;
        case 2:
                dequeue();
                break;
        case 3:
                frontOperation();
                break;
        case 4:
                rearOperation();
                break;
        case 5:
                display();
                break;
        case 6:
                exit(1);
        default:
            printf("Please enter a valid choice...!\n");
        }
    }
    while(choice!=0);
    return 0;
}
void enqueue()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(front==0 || rear==0)
    {
        front=newnode;
        rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=rear->next;
    }
    newnode->next=0;
    count++;
    printf("Item %d pushed in the queue successfully...!\n",rear->data);
}
void dequeue()
{
    struct node *temp;
    if(front==0 || rear==0)
        printf("Queue is empty item can't be popped...!\n");
    else if(front==rear)
    {
        front=0;
        rear=0;
    }
    else
    {
        int item;
        item=front->data;
        temp=front;
        front=front->next;
        free(temp);
        count--;
        printf("item %d popped from the queue successfully...!\n",item);
    }
}
void frontOperation()
{
    if(front==0 || rear==0)
        printf("Queue is empty...!\n");
    else
        printf("front item of the queue is the %d.\n",front->data);
}
void rearOperation()
{
    if(front==0 || rear==0)
        printf("Queue is empty...!\n");
    else
        printf("Rear item of the queue is the %d.\n",rear->data);
}
void display()
{
    struct node *temp;
    if(front==0 || rear==0)
        printf("Queue is empty...!\n");
    else
    {
        temp=front;
        while(temp->next!=0)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }

}

