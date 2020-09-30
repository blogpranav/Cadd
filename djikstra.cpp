#include <limits.h> 
#include <stdio.h> 

using namespace std;
int mindis(int dis[],bool spset[],int x)

{
	int min=INT_MAX,index;

	for(int i=0;i<x;i++)
	{
		if(spset[i]==false && dis[i]<=min)
			{
				min=dis[i];
				index=i;
			}

	}
	return index;
}

void djikstra(int graph[][9],int src)
{
	int dis[9];
	for(int i=0;i<9;i++)
		dis[i]=INT_MAX;
	bool spset[9];
	dis[src]=0;
	for(int i=0;i<8;i++)
	{
		int u=mindis(dis,spset,9);
		spset[u]=true;
		for(int l=0;l<9;l++)
		{
			if(!spset[l] && graph[u][l] && graph[u][l]!=INT_MAX && dis[u]+graph[u][l]<dis[l])
			{
				dis[l]=dis[u]+graph[u][l];
			}


		}

}
for(int i=0;i<9;i++)
	printf("%d vertex and dis %d\n",i,dis[i]);
	
}

int main()
{
	int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    djikstra(graph, 0); 
}