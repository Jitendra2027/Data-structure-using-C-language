#include<stdio.h>
#define vertex 5
void addEdge(int [][vertex],int,int);
void printGraph(int [][vertex]);
int main()
{
    int x,y,flag;
    int graph[vertex][vertex]={0};
    do
    {
        printf("Enter the source and destination vertex:");
        scanf("%d %d",&x,&y);
        addEdge(graph,x-1,y-1);
        printf("Enter 1 to continue or 0 to exit:");
        scanf("%d",&flag);
    }
    while(flag!=0);
    printGraph(graph);
    return 0;
}
void addEdge(int graph[][vertex],int src,int dest)
{
    //As undirected graph is symmetric so initialization with 1 be like:
    graph[src][dest]=1;
    graph[dest][src]=1;
}
void printGraph(int graph[][vertex])
{
    int i,j;
    printf("Adjacency matrix for the graph is:\n");
    for(i=0;i<vertex;i++)
    {
        for(j=0;j<vertex;j++)
            printf("%d ",graph[i][j]);
        printf("\n");
    }
}
