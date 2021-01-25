#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void deleteBeg();
void deleteEnd();
void deletePos();
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
    do
    {
        printf("\t\t\t\t\t***Enter your choice***\n");
        printf("1.CREATE LIST\t 2.DELETE FROM BEGIN\t 3.DELETE FROM END\t 4.DELETE FROM POSITION\t 5.DISPLAY\t 6.EXIT\n");
        printf("Your choice is:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
                create();
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
void deleteBeg()
{
    if(head==0)
        printf("List is empty deletion can't be performed...!\n");
    else
    {
        temp=head;
        head=head->next;
        head->previous=0;
        free(temp);
        count--;
        printf("Node deleted from beginning successfully...!\n");
    }
}
void deleteEnd()
{
     if(head==0)
        printf("List is empty deletion can't be performed...!\n");
     else
        {
            temp=tail;
            tail->previous->next=0;
            tail=tail->previous;
            free(temp);
            count--;
            printf("Node deleted from the end successfully...\n");
        }

}
//this function will delete the node from given position.
void deletePos()
{
    int i=1,pos;
     if(head==0)
        printf("List is empty deletion can't be performed...!\n");
     else
     {
         printf("Enter the position:");
         scanf("%d",&pos);
         if(pos==1)
            deleteBeg();
         else if(pos==count)
            deleteEnd();
         else
         {
             temp=head;
             while(i<pos)
             {
                 temp=temp->next;
                 i++;
             }
             temp->previous->next=temp->next;
             temp->next->previous=temp->previous;
             free(temp);
             count--;
             printf("Node deleted from %d position successfully...!\n");
         }
     }
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
