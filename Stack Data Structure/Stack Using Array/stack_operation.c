//stack is a linear type of data structure which follows last in first out or first in
//last out approach.operations of stack are push,pop,peek,is empty,is full,display etc.
//static or array representation of the stack data structure
#include<stdio.h>
void push(int);
void pop();
void peek();
void display();

#define N 10//we have fixed the size of stack with 10 statically
int stack[N];
int top=-1;
int main()
{
    char choice;
    do
    {
        printf("Enter your choice:\n");
        printf("1.PUSH\tT 2.POP\t 3.PEEK\t 4.DISPLAY");
        printf("\nYour choice is:");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1: ;
                int item;
                printf("Enter item to be pushed:");
                scanf("%d",&item);
                push(item);
                break;
        case 2:
                //does not need to pass any argument because item is deleted from top always.
                pop();
                break;
        case 3:
                peek();
                break;
        case 4:
                //display the stack items
                display();
                break;
        default:
                printf("Enter a valid choice...!");
        }
    }while(choice!=0);
    return 0;
}
void push(int x)
{
    //if stack is full and we are trying to insert more items.
    if(top==N-1)
        printf("Overflow occurred...!,item can't be inserted.");
    else
    {
        top++;
        stack[top]=x;
        printf("Item inserted successfully...!");
    }
}
//pop operation deletes the single item at a time from the top of the stack .
void pop()
{
    int item;
    if(top==-1)
        //if stack has no item to be popped.
        printf("Underflow occurred...!Item can't be popped.");
    else
    {
        item=stack[top];
        top--;
        printf("%d item popped from stack...!",item);
    }
}
//peek operation gives the top most element of the stack without deleting it.
void peek()
{
    if(top==-1)
        printf("Stack is empty so there is no peek item in the stack...!");
    else
        printf("peek item of the stack is %d",stack[top]);
}
//we are here printing the stack from top to bottom pattern.
void display()
{
    int i;
    printf("Your stack is:");
    for(i=top;i>=0;i--)
        printf("%d ",stack[i]);
}
//complexity analysis of stack
//Time Complexities of operations on stack:
//  ->push(), pop(), isEmpty() and peek() all take O(1) time.
//  ->We do not run any loop in any of these operations.

//Applications of stack:
//  Balancing of symbols
//  Infix to Postfix /Prefix conversion
//  Redo-undo features at many places like editors, photoshop.
//  Forward and backward feature in web browsers
//  Used in many algorithms like Tower of Hanoi, tree traversals, stock span problem, histogram problem.
//  Other applications can be Backtracking, Knight tour problem, rat in a maze, N queen problem and sudoku solver
//  In Graph Algorithms like Topological Sorting and Strongly Connected Components
