#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
    int vertex;
	struct _listnode *next;
} ListNode;

typedef struct _graph{
    int V;
    int E;
    int *visited;
    int **matrix;
}Graph;

typedef ListNode QueueNode;

typedef struct _queue{
   int size;
   QueueNode *head;
   QueueNode *tail;
} Queue;

int SD (Graph G, int v, int w);

void printGraphMatrix(Graph );

// You should not change the prototypes of these functions
void enqueue(Queue *qPtr, int item);
int dequeue(Queue *qPtr);
int getFront(Queue q);
int isEmptyQueue(Queue q);
void removeAllItemsFromQueue(Queue *qPtr);

int main()
{
    Graph g;
    int i,j;

    printf("Enter the number of vertices:\n");
//    scanf("%d",&g.V);
    g.V = 4;
    g.E = 0;
    g.matrix = (int **)malloc(g.V*sizeof(int *));
    for(i=0;i<g.V;i++)
        g.matrix[i] = (int *)malloc(g.V*sizeof(int));

    for(i=0;i<g.V;i++)
       for(j=0;j<g.V;j++)
           g.matrix[i][j] = 0;

    g.visited = (int *) malloc(sizeof(int)*g.V);
    for(i=0;i<g.V;i++) g.visited[i] = 0;

    int V1, V2;
    printf("Enter two vertices which are adjacent to each other:\n");
//    while(scanf("%d %d",&V1,&V2)==2)
//    {
//        if(V1>0 && V1<=g.V && V2>0 && V2<=g.V)
//        {
//            g.matrix[V1-1][V2-1] = 1;
//            g.matrix[V2-1][V1-1] = 1;
//            g.E++;
//        }
//        else
//            break;
//        printf("Enter two vertices which are adjacent to each other: (press a to stop)\n");
//    }
//    scanf("%*c");
    // printGraphMatrix(g);
//    g.matrix[0][1] = 1;
//    g.matrix[1][0] = 1;
//    g.matrix[0][2] = 1;
//    g.matrix[2][0] = 1;
//    g.matrix[1][3] = 1;
//    g.matrix[3][1] = 1;
//    g.matrix[1][4] = 1;
//    g.matrix[4][1] = 1;
//    g.E = 4;

//    g.matrix[0][1] = 1;
//    g.matrix[0][3] = 1;
//    g.matrix[1][2] = 1;
//    g.matrix[2][3] = 1;
//    g.matrix[3][4] = 1;
//    g.E = 2;



//    g.matrix[0][1] = 1;
//    g.matrix[1][0] = 1;
//    g.matrix[0][5] = 1;
//    g.matrix[5][0] = 1;
//    g.matrix[1][5] = 1;
//    g.matrix[5][1] = 1;
//    g.matrix[1][2] = 1;
//    g.matrix[2][1] = 1;
//    g.matrix[2][3] = 1;
//    g.matrix[3][2] = 1;
//    g.matrix[3][4] = 1;
//    g.matrix[4][3] = 1;
//    g.matrix[4][5] = 1;
//    g.matrix[5][4] = 1;
//    g.matrix[5][2] = 1;
//    g.matrix[2][5] = 1;
//    g.matrix[5][3] = 1;
//    g.matrix[3][5] = 1;
//    g.matrix[5][3] = 1;
//    g.matrix[3][5] = 1;
//    g.E = 9;

//    g.matrix[0][1] = 1;
//    g.matrix[1][0] = 1;
//    g.matrix[0][5] = 1;
//    g.matrix[5][0] = 1;
//    g.matrix[1][5] = 1;
//    g.matrix[5][1] = 1;
//    g.matrix[1][2] = 1;
//    g.matrix[2][1] = 1;
//    g.matrix[2][3] = 1;
//    g.matrix[3][2] = 1;
//    g.matrix[3][4] = 1;
//    g.matrix[4][3] = 1;
//    g.matrix[4][5] = 1;
//    g.matrix[5][4] = 1;
//    g.matrix[5][2] = 1;
//    g.matrix[2][5] = 1;
//    g.matrix[5][3] = 1;
//    g.matrix[3][5] = 1;
//    g.matrix[5][3] = 1;
//    g.matrix[3][5] = 1;
//    g.E = 9;


    g.matrix[0][2] = 1;
    g.matrix[2][0] = 1;
    g.matrix[1][3] = 1;
    g.matrix[3][1] = 1;
    printGraphMatrix(g);
    printf("Enter two vertices for finding their shortest distance: (press a to stop)\n");
//    scanf("%d %d", &i, &j);
    i = 1;
    j = 2;
    int d = SD(g,i,j);
    if(d==-1)
        printf("%d and %d are unconnected.\n",i,j);
    else
        printf("The shortest distance is %d\n",d);
    return 0;
}

int SD(Graph g, int v, int z){
    // Write your code here

    Queue queueGraph;
    queueGraph.head = NULL;
    queueGraph.tail = NULL;
    queueGraph.size = 0;


    //input 5 checking


    int m,checkConnectedV = 0,checkConnectedZ = 0;
    int countDistance[g.V];

    for(m = 0; m < g.V; m++)
        countDistance[m] = 0;

    for(m = 0; m < g.V; m++)
    {
        if(g.matrix[v-1][m] == 1)
            checkConnectedV++;

        if(g.matrix[m][v-1] == 1)
            checkConnectedV++;

        if(g.matrix[m][z-1] == 1)
            checkConnectedZ++;

        if(g.matrix[z-1][m] == 1)
            checkConnectedZ++;
    }

    if(checkConnectedV == 0 || checkConnectedZ == 0)
        return -1;


    enqueue(&queueGraph,v);
    g.visited[v-1] = 1;
    while(!isEmptyQueue(queueGraph))
    {
        int frontVertex = getFront(queueGraph); dequeue(&queueGraph);

        if(frontVertex == z)
            return countDistance[frontVertex-1];

        for(m = 0; m < g.V; m++)
        {
            if(g.matrix[frontVertex-1][m] == 1 && g.visited[m] == 0)
            {
                enqueue(&queueGraph,m+1);
                g.visited[m] = 1;
                countDistance[m] = countDistance[frontVertex-1] + 1;
            }
        }

    }

    return -1;

}

void printGraphMatrix(Graph g)
{
    int i,j;

    for(i=0;i<g.V;i++){
        for(j=0;j<g.V;j++)
            printf("%d\t",g.matrix[i][j]);
        printf("\n");
    }

}


void enqueue(Queue *qPtr, int item) {
    QueueNode *newNode;
    newNode = malloc(sizeof(QueueNode));
    if(newNode==NULL) exit(0);

    newNode->vertex = item;
    newNode->next = NULL;

    if(isEmptyQueue(*qPtr))
        qPtr->head=newNode;
    else
        qPtr->tail->next = newNode;

    qPtr->tail = newNode;
    qPtr->size++;
}

int dequeue(Queue *qPtr) {
    if(qPtr==NULL || qPtr->head==NULL){ //Queue is empty or NULL pointer
        return 0;
    }
    else{
       int headValue = qPtr->head->vertex;
       QueueNode *temp = qPtr->head;
       qPtr->head = qPtr->head->next;
       if(qPtr->head == NULL) //Queue is emptied
           qPtr->tail = NULL;

       free(temp);
       qPtr->size--;
       return headValue;
    }
}

int getFront(Queue q){
    return q.head->vertex;
}

int isEmptyQueue(Queue q) {
    if(q.size==0) return 1;
    else return 0;
}

void removeAllItemsFromQueue(Queue *qPtr)
{
	while(dequeue(qPtr));
}
