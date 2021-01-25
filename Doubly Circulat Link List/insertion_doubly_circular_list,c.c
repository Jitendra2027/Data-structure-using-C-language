#include<stdio.h>
#include<stdlib.h>
//void create();
void insertBeg();
void insertEnd();
void insertPos();
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
    printf("\t\t******Insertion operation for the doubly circular link list******\n");
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

/*void create()
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
*/
void insertBeg()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&newnode->data);
    if(head==0)//condition when list has no nodes and we are inserting first node
    {
        tail=head=newnode;
        newnode->next=newnode;//newnode->next=tail
        newnode->previous=tail;//newnode->previous=newnode
    }
    else
    {
        newnode->next=head;
        newnode->previous=tail;
        head->previous=newnode;
        head=newnode;
        tail->next=newnode;
    }
    count++;
    printf("Node inserted successfully at the begin.\n");
}
void insertEnd()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&newnode->data);
    if(head==0)//condition when list has no nodes and we are inserting first node
    {
        tail=head=newnode;
        newnode->next=newnode;//newnode->next=tail
        newnode->previous=tail;//newnode->previous=newnode
    }
    else
    {
        newnode->next=head;
        newnode->previous=tail;
        tail->next=newnode;
        head->previous=newnode;
        tail=newnode;
    }
    count++;
    printf("Node inserted successfully at the end.\n");
}
void insertPos()
{
    int pos,i=1;
    printf("Enter the position:");
    scanf("%d",&pos);
    if(pos==1)
    {
        insertBeg();
    }
    else if(pos==count+1)
        insertEnd();
    else if(pos<0 || pos>count+1)
        printf("Enter a valid position you have only %d nodes...!\n",count);
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
        printf("Node inserted successfully at position %d.\n",pos);
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


