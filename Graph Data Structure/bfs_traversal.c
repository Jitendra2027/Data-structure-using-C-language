#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define size 5
struct vertex
{
    int label;
    bool visited;
};
struct queue
{
    int front;
    int rear;
    int items[size];
    int count;
}q;

struct vertex *verticesArray[size];
int vertexCount=0;
int adjmatrix[size][size]={0};
void addVertex(int data)
{
    struct vertex *v=(struct vertex*)malloc(sizeof(struct vertex));
    v->label=data;
    v->visited=false;
    verticesArray[vertexCount++]=v;
}
void addEdge(int src,int dest)
{
    adjmatrix[src][dest]=1;
    adjmatrix[dest][src]=1;
}
int adjVertex(int v)
{
    for(int i=0;i<vertexCount;i++)
    {
        if(adjmatrix[v][i]==1 && verticesArray[i]->visited==false)
            return i;
    }
    return -1;
}
void displayVertex(int index)
{
    printf("%d ",verticesArray[index]->label);
}
void insert(struct queue *q,int index)
{
    q->items[++q->rear]=index;
    q->count++;
}
int dequeue(struct queue *q)
{
    q->count--;
    return q->items[q->front++];
}
bool isEmpty(struct queue *q)
{
    return q->count==0;
}
struct queue* createQueue()
{
  struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  q->count=0;
  return q;
}
void bfs()
{
    int i,unvisitedVertex;
    struct queue* q = createQueue();
    verticesArray[0]->visited=true;
    displayVertex(0);
    insert(q,0);
    while(!isEmpty(q))
    {
        int tempVertex=dequeue(q);
        while(adjVertex(tempVertex)!=-1)
        {
            int unvisited=adjVertex(tempVertex);
            verticesArray[unvisited]->visited=true;
            displayVertex(unvisited);
            insert(q,unvisited);
        }
    }

}
int main()
{
    int v;
    addVertex(15);
    addVertex(20);
    addVertex(80);
    addVertex(19);
    addVertex(17);

    addEdge(0,1);
    addEdge(0,2);
    addEdge(0,3);
    addEdge(1,4);
    addEdge(2,4);
    addEdge(3,4);

    //printf("Enter the starting vertex for the traversal:");
    //scanf("%d",&v);

    bfs();
    return 0;
}
