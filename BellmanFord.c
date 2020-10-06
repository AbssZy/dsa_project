#include <stdio.h>
#include <stdlib.h>
#define INFINITY 99999
//struct for the edges of the graph
struct Edge {
int u;//start vertex of the edge
int v;//end vertex of the edge
int w;//weight of the edge (u,v)
};
//Graph - it consists of edges
struct Graph {
int V;//total number of vertices in the graph
int E;//total number of edges in the graph
struct Edge *edge;//array of edges
};
int main()
{
    int x1,x2,x3,i;//create graph
struct Graph *g = (struct Graph*)malloc(sizeof(struct Graph));
printf("Enter total number of investers : ");
scanf("%d",&x1);
g->V = x1; //total vertices
printf("Enter total number of transaction : ");
scanf("%d",&x2);
g->E = x2;//total edges
g->edge = (struct Edge*)malloc(x2 * sizeof(struct Edge));//array of
edges for graph
for(i=0;i<x2;i++)
    {
    int a1=0,a2=0,a3=0;
    printf("Enter the details of %d transaction\n",i+1);
    printf("Enter the sender : ");
    scanf("%d",&a1);
    g->edge[i].u = a1;
    printf("Enter the reciever : ");
    scanf("%d",&a2);
    g->edge[i].v = a2;
    printf("Enter the amount: ");
    scanf("%d",&a3);
    g->edge[i].w = a3;
    }
    printf("Enter the source: ");
    scanf("%d",&x3);
bellmanford(g, x3); //0 is the source vertex
    return 0;
}
void display(int x[], int size)
{
int i;printf("Person Miminum amount of profit or loss \n");
for(i = 0; i < size; i ++)
{
printf("%d \t\t %d\n",i+1,x[i]);
}
}
void bellmanford(struct Graph *g, int source)
{
//variables
int i, j, a, b, c;
//total vertex in the graph g
int tV = g->V;//total edge in the graph g
int tE = g->E;//distance array
//size equal to the number of vertices of the graph g
int d[tV];//predecessor array
//size equal to the number of vertices of the graph g
//int p[tV];//step 1: fill the distance array
for (i = 0; i < tV; i++)
{
d[i] = INFINITY;
//p[i] = 0;
}
//mark the source vertex
d[source] = 0;//step 2: relax edges |V| - 1 times
for(i = 1; i <= tV-1; i++)
{
for(j = 0; j < tE; j++)
{//get the edge data
a = g->edge[j].u;
b = g->edge[j].v;
c = g->edge[j].w;
if(d[a] != INFINITY && d[b] > d[a] + c)
{
d[b] = d[a] + c;
//p[b] = a;
}
}
}//step 3: detect negative cycle
//if value changes then we have a negative cycle in the graph
//and we cannot find the shortest distances
for(i = 0; i < tE; i++)
{
a = g->edge[i].u;
b = g->edge[i].v;
c = g->edge[i].w;
if(d[a] != INFINITY && d[b] > d[a] + c)
{
printf("Negative weight cycle detected!\n");
return;
}
}
//No negative weight cycle found!
//print the distance array!
display(d, tV);
}