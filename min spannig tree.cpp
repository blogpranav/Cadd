#include <bits/stdc++.h> 
using namespace std; 

class Edge
{
public:
	int src,dest,weight;
}

class Graph
{
public:
	int v,e;
	Edge *edge
}

class subset
{
	int parent,rank;
}
Graph* creategraph(Graph *graph,int v,int e)
{
	Graph graph=new Graph();
	this->v=v;
	this->e=e;
	graph->edge=new Edge[e];
		return graph;

} 

// Graph addedge(Graph *graph,int e,int src,int dest)
// {
// 	graph->edge[e].src=src;
// 	graph->edge[e].dest=dest;
// }

int find(subset subsets[],int i)
{
	if(subsets[i].parent!=i)
		subsets[i].parent=find(subsets,subsets[i].parent)
	return subsets[i].parent;
	
}

void union( subset subsets[],int x,int y)
{
	int xset=find(subsets,x);
	int yset=find(subsets,y);

	if(subsets[xset].rank<subsets[yset].rank)
		subsets[xset].parent=yset;
	else if(subsets[xset].rank>subsets[yset].rank)
		subsets[yset]=xset;
	else
	{
		subsets[yset]=xset;
		subsets[xset].root++;

	}
}

int comp(const *a,cont *b)
{
	Edge* a1=(Edge)*a;
	Edge* b1=(Edge)*b;
	return a1->weight>b1->weight;
}


void mst(Graph *graph)
{
	int a=0,l=0;
	int x=graph->v;
	Edge res[x];
	qsort(q->edge,q->v,sizeof(q->edge[0]),comp);
	subset *subsets=new subset[x];
	for(int o=0;o<x;o++)
	{
		subsets[o].parent=o;
		subset[o].rank=0;
	}


	while(a<x-1 && l <graph->e)
	{
		Edge op=graph->edge[l++];
		int f=find(subsets,graph->edge[l].src);
		int g=find(subsets,graph->edge[l].dest);
		if(f!=g)
		{
			res[a++]=op;
			union(subsets,f,g);

		}



	}

for (z = 0; z < a; ++z)  
        cout<<res[z].src<<" -- "<<res[z].dest<<" == "<<res[z].weight<<endl;  
    return;  
}

int main()
{
	Graph *graph=creategraph(4,5);
	 graph->edge[0].src = 0;  
    graph->edge[0].dest = 1;  
    graph->edge[0].weight = 10;  
  
    // add edge 0-2  
    graph->edge[1].src = 0;  
    graph->edge[1].dest = 2;  
    graph->edge[1].weight = 6;  
  
    // add edge 0-3  
    graph->edge[2].src = 0;  
    graph->edge[2].dest = 3;  
    graph->edge[2].weight = 5;  
  
    // add edge 1-3  
    graph->edge[3].src = 1;  
    graph->edge[3].dest = 3;  
    graph->edge[3].weight = 15;  
  
    // add edge 2-3  
    graph->edge[4].src = 2;  
    graph->edge[4].dest = 3;  
    graph->edge[4].weight = 4;
    graph.mst(graph);

}