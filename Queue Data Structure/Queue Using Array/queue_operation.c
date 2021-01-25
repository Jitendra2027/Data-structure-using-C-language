//Queue is a linear type of data structure in which data is stored in FIFO (first out first in)
//or LILO(last in last out).
//This is the static representation of the queue in which we have fixed the size of queue.

#include<stdio.h>
void enqueue(int);
void dequeue();
void frontOperation();
void rearOperation();
void display();

#define N 15
int queue[N];
int front=-1,rear=-1;
int main()
{
    int choice;
    do
    {
        printf("Enter your choice:");
        printf(" 1.ENQUEUE\t 2.DEQUEUE\t 3.FRONT\t 4.REAR\t 5.DISPLAY\t");
        printf("\nYour choice is:");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1: ;//; denotes the empty statement only statements are allowed after label
                 //declaration is not statement so we made a empty statement.
                int item;
                printf("Enter the item to be inserted:");
                scanf("%d",&item);
                enqueue(item);
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
        default:
                printf("Enter a valid choice...!");
        }
    }
    while(choice!=0);

    return 0;
}
//enqueue operation inserts item in the queue from rear end.
void enqueue(int x)
{
    //when queue is totally empty
    if(front==-1 && rear==-1)
    {
        front=0;//set to 0
        rear=0;//set to 0
        queue[rear]=x;
        printf("Item %d inserted in queue successfully...!\n",x);
    }
    //when queue is full i.e. rear index reaches size-1.
    else if(rear==N-1)
        printf("Overflow occurred...!Item can't be inserted.\n");
    //normal case when there is already items present in the queue and we are inserting more.
    else
    {
        rear++;
        queue[rear]=x;
        printf("Item %d inserted in queue successfully...!\n",x);
    }
}
//this operation deletes the item from the queue from the front end.
void dequeue()
{
    //when queue is empty
    if(front==-1 && rear==-1)
    {
        printf("Underflow occurred...!Item can't be deleted.\n");
    }
    //condition when there is only single element remained in the queue
    //after deletion queue will be totally empty so front and rear both set to -1.
    else if(front==rear)
    {
        printf("Item %d deleted from queue successfully...!\n",queue[front]);
        rear=-1;
        front=-1;
    }
    else
    {
        printf("Item %d deleted from queue successfully...!\n",queue[front]);
        front++;
    }
}
//this will give the item value present at front end.
void frontOperation()
{
    if(front==-1 && rear==-1)
        printf("Queue is empty,front element is nothing...!\n");
    else
        printf("Front item of the queue is %d\n",queue[front]);
}
//this will give the item value present at rear end.
void rearOperation()
{
    if(front==-1 && rear==-1)
        printf("Queue is empty,rear element is nothing...!\n");
    else
        printf("Rear item of the queue is %d\n",queue[rear]);
}
void display()
{
    int i;
    if(front==rear)
        printf("Your queue is empty...!\n");
    else
    {
        printf("Your queue is:");
        for(i=front;i<=rear;i++)
            printf("%d ",queue[i]);
    }
}


//Complexity Analysis of Queue Operations
//Just like Stack, in case of a Queue too, we know exactly, on which position new element will be added and from where an element will be removed, hence both these operations requires a single step.
//  Enqueue: O(1)
//  Dequeue: O(1)
//  Size: O(1)

//Applications of Queue
//  Queue, as the name suggests is used whenever we need to manage any group of objects in
//  an order in which the first one coming in, also gets out first while the others wait
//  for their turn, like in the following scenarios:

//1.Serving requests on a single shared resource, like a printer, CPU task scheduling etc.
//2.In real life scenario, Call Center phone systems uses Queues to hold people calling them in an order, until a service representative is free.
//3.Handling of interrupts in real-time systems. The interrupts are handled in the same order as they arrive i.e First come first served.

//drawback of queue=>we can't insert element in the queue when it's rear index is equal to
//size-1 rather the cells are empty.

