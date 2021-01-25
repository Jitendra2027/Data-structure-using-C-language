//In this traversing we will print the tree data level by level.
//Algo:-printLevelorder(tree)
//1) Create an empty queue q
//2) temp_node = root /*start from root*/
//3) Loop while temp_node is not NULL
//    a) print temp_node->data.
//    b) Enqueue temp_node’s children
//      (first left then right children) to q
//    c) Dequeue a node from q.
#include<stdio.h>
#include<stdlib.h>
#define MAX 500
struct node* create();

struct node** createQueue(int *, int *);
void enQueue(struct node **, int *, struct node *);
struct node *deQueue(struct node **, int *);
struct node
{
    int data;
    struct node *left,*right;
};
void printLevelOrder(struct node* root)
{
    int rear=0, front=0;
    //here queue is two dimensional because it will contain the address of the node.
    struct node **queue =
        (struct node **)malloc(sizeof(struct node*)
                                       *MAX);
    struct node *temp_node = root;

    while (temp_node)
    {
        printf("%d ", temp_node->data);

        /*Enqueue left child */
        if (temp_node->left)
            enQueue(queue, &rear, temp_node->left);

        /*Enqueue right child */
        if (temp_node->right)
            enQueue(queue, &rear, temp_node->right);

        /*Dequeue node and make it temp_node*/
        temp_node = deQueue(queue, &front);
    }
}
void enQueue(struct node **queue, int *rear,
                             struct node *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}

struct node *deQueue(struct node **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}
int main()
{
    struct node *root;
    root=0;
    root=create();
    printf("Level order traversal of the tree:");
    printLevelOrder(root);
    return 0;
}
struct node* create()
{
     struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data(enter -1 for termination or no node):");
    scanf("%d",&newnode->data);
    if(newnode->data==-1)
        return 0;
    printf("Enter the left child of %d\n",newnode->data);
    newnode->left=create();
    printf("Enter the right child of %d\n",newnode->data);
    newnode->right=create();
    return newnode;
}

