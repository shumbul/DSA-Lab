///bellman's algo
#include <stdio.h>
void bellman(int G[20][20] , int V, int E, int e[20][2])
{
    int i,u,v,k,d[20],p[20],S,flag=1;
    for(i=0;i<V;i++)
        d[i] = 1000 , p[i] = -1 ;
        printf("Enter source: \n");
        scanf("%d",&S);
        d[S-1]=0 ;
    for(i=0;i<V-1;i++)    //visiting all nodes
    {
        for(k=0;k<E;k++)   //visiting the vertices of all nodes
        {
            u = e[k][0] , v = e[k][1] ;
            if(d[u]+G[u][v] < d[v])
                d[v] = d[u] + G[u][v] , p[v]=u ;   //updating the minimum distance
        }
    }
    for(k=0;k<E;k++)
        {
            u = e[k][0] , v = e[k][1] ;
            if(d[u]+G[u][v] < d[v])
                flag = 0 ;
        }  //checking if there is still a hope of any change in mium distance, this ussually happens in case of negative edges
        if(flag)
            for(i=0;i<V;i++)
                printf("Vertex %d  cost = %d\n",i+1,d[i]);
   else
   printf("negative weighted cycle\n");

      }

int main()
{
    int V,e[20][2],G[20][20],i,j,k=0;
     printf(" IMPLEMENTING BELLMAN'S ALGORITHM \n\n");
    printf("Enter no. of vertices: \n");
    scanf("%d",&V);
    printf("Enter the adjacency matrix of the graph:\n");
    for(i=0;i<V;i++)
       {
        for(j=0;j<V;j++)
        {
            scanf("%d",&G[i][j]);
            if(G[i][j]!=0)
                e[k][0]=i,e[k++][1]=j; //filling from both the directions
        }
        printf("\n");
        }

    bellman(G,V,k,e);
       
    return 0;
}
