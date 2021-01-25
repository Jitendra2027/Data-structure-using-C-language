//In stack implementation using link list we insert the node only on begin of the list because
//it has time complexity of the order o(1);
//if we insert node at the end of the list then it has time complexity of the order o(n),because
//we have to traverse the whole list.
#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void peek();
void display();

struct node
{
    int data;
    struct node *next;
};
struct node *top=0;
int count=0;
int main()
{
    int choice;
    do
    {
        printf("Enter your choice:");;
        printf("1.PUSH\t 2.POP\t 3.PEEK\t 4.DISPLAY\t 5.EXIT\n");
        printf("Your choice is:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
                push();
                break;
        case 2:
                pop();
                break;
        case 3:
                peek();
                break;
        case 4:
                display();
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
void push()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&newnode->data);
    newnode->next=top;
    top=newnode;
    count++;
    printf("Item %d pushed in the stack successfully...!\n",newnode->data);
}
void pop()
{
    struct node *temp;
    if(top==0)
        printf("Stack is empty item can't be popped...!\n");
    else
    {
        temp=top;
        int item=top->data;
        top=top->next;
        free(temp);
        count--;
        printf("item %d popped from the stack successfully...!\n",item);
    }
}
void peek()
{
    if(top==0)
        printf("Stack is empty...!\n");
    else
        printf("Peek item of the stack is the %d.\n",top->data);
}
void display()
{
    struct node *temp;
    if(top==0)
        printf("Stack is empty...!\n");
    else
    {
        temp=top;
        while(temp->next!=0)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
        printf("Number of the items in the stack is:%d\n",count);
    }

}
