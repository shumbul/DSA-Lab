//dijkstra's alorithm
#include <stdio.h>
void dij(int n,int v,int cost[10][10],int dist[])
{
 int i,u,count,w,flag[10],min;
 for(i=1;i<=n;i++)
  flag[i]=0,dist[i]=cost[v][i];
 count=2;
 while(count<=n)
 {
  min=99;
  for(w=1;w<=n;w++)
   if(dist[w]<min && !flag[w])
    min=dist[w],u=w;
  flag[u]=1;
  count++;
  //relaxing condition
  for(w=1;w<=n;w++)
   if((dist[u]+cost[u][w]<dist[w]) && !flag[w])
    dist[w]=dist[u]+cost[u][w];
 }
}

int main()
{
 int n,v,i,j,cost[10][10],dist[10],tcost=0;

 printf(" Enter the number of nodes:");
 scanf("%d",&n);
 printf("\n Enter the matrix:\n");
 for(i=1;i<=n;i++)
  {
  for(j=1;j<=n;j++)
  {
   scanf("%d",&cost[i][j]);
   if(cost[i][j]==0)
    cost[i][j]=999;          //we consider this cost for a node at infinite distance
  }
  printf("\n");
  }
 printf("\nEnter the source node:");
 scanf("%d",&v);
 
 //main operation
 dij(n,v,cost,dist);
 
 printf("\nShortest path:\n");
 for(i=1;i<=n;i++)
  if(i!=v)
   {
   printf("%d->%d,cost=%d\n",v,i,dist[i]);
   tcost+=dist[i];
   }
   printf("Total cost in the minimum spanning tree = %d\n",tcost);
return 0;
}
