#include<stdio.h>
#include<stdlib.h>
struct node
{
    int dest;
    struct node *next;
};
struct list
{
    struct node *head;
};
struct graph
{
    int vertex;
    struct list *array;
};
struct graph* createGraph(int v)
{
    struct graph *g=(struct graph *)malloc(sizeof(struct graph));
    g->vertex=v;
    g->array=(struct list*)malloc(sizeof(struct list)*v);
    for(int i=0;i<v;i++)
        g->array[i].head=NULL;
    return g;
}
void addEdge(struct graph *g,int src,int dest)
{
    struct node *newnode1=(struct node *)malloc(sizeof(struct node));
    newnode1->next=NULL;
    newnode1->dest=dest;

    // Add an edge from src to dest.  A new node is
    // added to the adjacency list of src.  The node
    // is added at the beginning
    newnode1->next=g->array[src].head;
    g->array[src].head=newnode1;

    // Since graph is undirected, add an edge from
    // dest to src also
    struct node *newnode2=(struct node *)malloc(sizeof(struct node));
    newnode2->next=NULL;
    newnode2->dest=src;

    newnode2->next=g->array[dest].head;
    g->array[dest].head=newnode2;
}
void printGraph(struct graph *g)
{
    for(int i=0;i<g->vertex;i++)
    {
        struct node* pCrawl = g->array[i].head;
        printf("\n Adjacency list of vertex %d\n head ", i);
        while(pCrawl)
        {
            printf("->%d",pCrawl->dest);
            pCrawl=pCrawl->next;
        }
        printf("\n");
    }
}
int main()
{
    int v;
    int s,d,i;
    printf("Enter the numbers of vertex:");
    scanf("%d",&v);
    struct graph *g=createGraph(v);
    do
    {
        printf("Enter the source and destination node index for the edge creation:");
        scanf("%d %d",&s,&d);
        addEdge(g,s,d);
        printf("Enter 1 to add more edge or 0 to see adjacency list:-");
        scanf("%d",&i);
    }
    while(i!=0);
    printGraph(g);
    return 0;
}
