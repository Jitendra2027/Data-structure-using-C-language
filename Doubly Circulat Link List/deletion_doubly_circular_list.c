#include<stdio.h>
#include<stdlib.h>
void create();
void deleteBeg();
void deleteEnd();
void deletePos();
void printList();
struct node
{
    int data;
    struct node *next,*previous;
};
struct node *head=0,*tail=0,*temp,*newnode;
int count=0;
int main()
{
    int i,choice;
    printf("Before performing the deletion operation first create the doubly circular link list:-\n");
    create();
    printf("Now perform the deletion operation:=\n");
    do
    {
        printf("Enter your choice:");
        printf("1.DELETE FROM BEGIN\t 2.DELETE FROM END\t 3.DELETE FROM POSITION\t 4.DISPLAY\t 5.EXIT\n");
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
            head=tail=newnode;
        }
        else
        {
            tail->next=newnode;
            newnode->previous=tail;
            tail=newnode;
        }
        newnode->next=head;
        head->previous=newnode;
        count++;
        printf("Do you want to create more node->(1/0):");
        scanf("%d",&i);
    }
    while(i!=0);
}
void deleteBeg()
{
    temp=head;
    if(head==0)//condition when list has no nodes and we are deleting first node
    {
        printf("Sorry list is empty deletion can't be performed...!\n");
    }
    else if(head->next==head)
    {
        head=tail=0;
        free(temp);
        count--;
    }
    else
    {
        head=head->next;
        head->previous=tail;
        tail->next=head;
        free(temp);
        count--;
    }
    printf("Node deleted successfully from the begin.\n");
}
void deleteEnd()
{
    temp=tail;
    if(head==0)//condition when list has no nodes and we are deleting first node
    {
        printf("Sorry list is empty deletion can't be performed...!\n");
    }
    else if(head->next==head)//tail->next=tail or tail->previous=tail
    {
        head=tail=0;
        free(temp);
        count--;
    }
    else
    {
        tail=tail->previous;
        tail->next=head;
        head->previous=tail;
        free(temp);
        count--;
    }
    printf("Node deleted successfully from the end.\n");
}
void deletePos()
{
    int pos,i=1;
    printf("Enter the position:");
    scanf("%d",&pos);
    if(pos==1)
    {
        deleteBeg();
    }
    else if(pos==count)
        deleteEnd();
    else if(pos<0 || pos>count)
        printf("Enter a valid position you have only %d nodes...!\n",count);
    else
    {
        temp=head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        temp->next->previous=temp->previous;
        temp->previous->next=temp->next;
        free(temp);
        count--;
        printf("Node deleted successfully from position %d.\n",pos);
    }
}
void printList()
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



