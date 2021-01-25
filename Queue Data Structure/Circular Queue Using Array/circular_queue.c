//In a Linear queue, once the queue is completely full, it's not possible to insert more
//elements.Circular Queue is a linear data structure in which the operations are performed
//based on FIFO (First In First Out) principle and the last position is connected back to
//the first position to make a circle. It is also called ‘Ring Buffer’.
#include<stdio.h>
void enqueue(int);
void dequeue();
void frontOperation();
void rearOperation();
void display();

#define N 5
int circularQueue[N];
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
//enqueue operation inserts item in the circular queue from rear end.
void enqueue(int x)
{
    //when queue is totally empty
    if(front==-1 && rear==-1)
    {
        front=0;//set to 0
        rear=0;//set to 0
        circularQueue[rear]=x;
        printf("Item %d inserted in circular queue successfully...!\n",x);
    }
    //when  circular queue is full i.e. rear index and front index are conjugate(front==rear-1).
    else if((rear+1)%N==front)
        printf("Overflow occurred...!Item can't be inserted.\n");
    //normal case when there is already items present in the queue and we are inserting more.
    else
    {
        rear=(rear+1)%N;
        circularQueue[rear]=x;
        printf("Item %d inserted in circular queue successfully...!\n",x);
    }
}
//this operation deletes the item from the queue from the front end.
void dequeue()
{
    //when circular queue is empty
    if(front==-1 && rear==-1)
    {
        printf("Underflow occurred...!Item can't be deleted.\n");
    }
    //condition when there is only single element remained in the circular queue
    //after deletion queue will be totally empty so front and rear both set to -1.
    else if(front==rear)
    {
        printf("Item %d deleted from queue successfully...!\n",circularQueue[front]);
        rear=-1;
        front=-1;
    }
    else
    {
        printf("Item %d deleted from queue successfully...!\n",circularQueue[front]);
        front=(front+1)%N;
    }
}
//this will give the item value present at front end.
void frontOperation()
{
    if(front==-1 && rear==-1)
        printf("Queue is empty,front element is nothing...!\n");
    else
        printf("Front item of the queue is %d\n",circularQueue[front]);
}
//this will give the item value present at rear end.
void rearOperation()
{
    if(front==-1 && rear==-1)
        printf("Queue is empty,rear element is nothing...!\n");
    else
        printf("Rear item of the queue is %d\n",circularQueue[rear]);
}
void display()
{
    int i;
    if(front==rear)
        printf("Your queue is empty...!\n");
    else
    {
        printf("Your queue is:");
        for(i=front;i!=rear;i=(i+1)%N)
            printf("%d ",circularQueue[i]);
        printf("%d\n",circularQueue[i]);
    }
}
//Time Complexity:
// Time complexity of enQueue(), deQueue() operation is O(1) as there is no loop in any
// of the operation.

//Applications:
// 1.Memory Management: The unused memory locations in the case of ordinary queues
//   can be utilized in circular queues.
// 2.Traffic system: In computer controlled traffic system, circular queues are used
//   to switch on the traffic lights one by one repeatedly as per the time set.
// 3.CPU Scheduling: Operating systems often maintain a queue of processes that are
//   ready to execute or that are waiting for a particular event to occur.
