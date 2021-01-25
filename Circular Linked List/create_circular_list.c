//Circular linked list is a linked list where all nodes are connected to form a circle.
//There is no NULL at the end. A circular linked list can be a singly circular linked list
//or doubly circular linked list.


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
        printf("1.CREATE CIRCULAT LIST\t 2.DISPLAY CIRCULAR LIST\t 3.EXIT\n");
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
        newnode->next=head;//last node address pointer contains the address of the first node
        //and make the list circular.
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
        while(temp->next!=head)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
        printf("\n");
        printf("Number of the nodes in the linked list are:%d\n",count);
    }
}

//Advantages of the circular link list
//Advantages of Circular Linked Lists:
//  1) Any node can be a starting point. We can traverse the whole list by starting from
//  any point. We just need to stop when the first visited node is visited again.
//  2) Useful for implementation of queue. Unlike this implementation, we don’t need
//  to maintain two pointers for front and rear if we use circular linked list. We can
//  maintain a pointer to the last inserted node and front can always be obtained as next
//  of last.
//  3) Circular lists are useful in applications to repeatedly go around the list. For
//  example, when multiple applications are running on a PC, it is common for the operating
//  system to put the running applications on a list and then to cycle through them, giving
//  each of them a slice of time to execute, and then making them wait while the CPU is given
//  to another application. It is convenient for the operating system to use a circular list
//  so that when it reaches the end of the list it can cycle around to the front of the list.
//  4) Circular Doubly Linked Lists are used for implementation of advanced data
//  structures like Fibonacci Heap.
