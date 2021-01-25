#include<stdio.h>
#include<stdlib.h>

void printList();
void createList();
void deleteBeg();
void deleteEnd();
void deletePos();

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
        printf("1.CREATE CIRCULAR LIST\t 2.DELETE FROM BEGIN\t 3.DELETE FROM END\t 4.DELETE FROM POSITION\t 5.DISPLAY\t 6.EXIT\n");
        printf("Your choice is:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    createList();
                    break;
            case 2:
                    deleteBeg();
                    break;
            case 3:
                    deleteEnd();
                    break;
            case 4:
                    deletePos();
                    break;
            case 5:
                    printList();
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
void deleteBeg()
{
    temp=tail->next;
    if(tail==0)
        printf("Your list is empty deletion can't be performed...!\n");
    else if(tail==tail->next)//list has only one node
    {
        tail=0;
        free(temp);
        printf("Node deleted from the begin successfully...!\n");
        count--;
    }
    else
    {
        tail->next=temp->next;
        free(temp);
        printf("Node deleted from the begin successfully...!\n");
        count--;
    }
}
void deleteEnd()
{
    struct node *previous,*current;
    if(tail==0)
        printf("Your list is empty deletion can't be performed...!\n");
    else if(tail==tail->next)//list has only one node
    {
        tail=0;
        free(temp);
        printf("Node deleted from the end successfully...!\n");
        count--;
    }
    else
    {
        current=tail->next;
        while(current->next!=tail->next)
        {
            previous=current;//previous node now points to second last node while
            //current node points to last node or tail node
            current=current->next;
        }
        previous->next=tail->next;
        tail=previous;
        free(current);
        printf("Node deleted from the end successfully...!\n");
        count--;
    }
}
void deletePos()
{
    int pos,i=1;
    printf("Enter the position:");
    scanf("%d",&pos);
    if(pos==1)
        deleteBeg();
    else if(pos==count)
        deleteEnd();
    else if(pos<0 || pos>count)
        printf("Deletion can't be performed you have only %d nodes...!\n",count);
    else
    {
        struct node *current,*nextnode;
        current=tail->next;//current node points to the first node initially and after traverse
        //it is points to the node before nextnode.
        while(i<pos-1)
        {
            current=current->next;
            i++;
        }
        nextnode=current->next;//nextnode pointer variable contains the address of the node
        //which is to be freed
        current->next=nextnode->next;
        free(nextnode);
        count--;
        printf("Node deleted from %d position successfully...!\n",pos);
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

