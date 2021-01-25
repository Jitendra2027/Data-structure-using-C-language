#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define size 5
struct vertex
{
    char data;
    bool visited;
};
struct stack
{
    int item[size];
    int top;
};
struct vertex *vertexArray[size];
int vertexCount=0;
int adjmatrix[size][size]={0};
void addVertex(int data)
{
    struct vertex *v=(struct vertex*)malloc(sizeof(struct vertex));
    v->data=data;
    v->visited=false;
    vertexArray[vertexCount++]=v;
}
void addEdge(int src,int dest)
{
    adjmatrix[src][dest]=1;
    adjmatrix[dest][src]=1;
}
void displayVertex(int index)
{
    printf("%c ",vertexArray[index]->data);
}
int adjVertex(int key)
{
    for(int i=0;i<vertexCount;i++)
    {
        if(adjmatrix[key][i]==1 && vertexArray[i]->visited==false){
            return i;
        }
    }
    return -1;
}
struct stack * createStack()
{
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->top=-1;
    return s;
}
void push(struct stack *s,int index)
{
    s->item[++s->top]=index;
}
int pop(struct stack *s)
{
    return s->item[s->top--];
}
int peek(struct stack *s)
{
    return s->item[s->top];
}
bool isEmpty(struct stack *s)
{
    return s->top==-1;
}
void dfs()
{
    struct stack *s=createStack();
    vertexArray[0]->visited=true;
    displayVertex(0);
    push(s,0);
    while(!isEmpty(s))
    {
        int unvisited=adjVertex(peek(s));
        if(unvisited==-1){
            pop(s);
        }
        else
        {
            vertexArray[unvisited]->visited=true;
            displayVertex(unvisited);
            push(s,unvisited);
        }
    }
}
int main()
{
    addVertex('S');
    addVertex('A');
    addVertex('B');
    addVertex('C');
    addVertex('D');

    addEdge(0,1);
    addEdge(0,2);
    addEdge(0,3);
    addEdge(1,4);
    addEdge(2,4);
    addEdge(3,4);

    dfs();
    return 0;
}
