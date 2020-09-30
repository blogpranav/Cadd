#include<bits/stdc++.h>
using namespace std;

class Edge
{
public:
	int src,dest,weight;
};
class Graph
{
public:
	int v,e;
	Edge *edge;
};

class subset
{
public:
	int parent,rank;
};

Graph* creategraph(int v,int e)

{

	Graph *graph=new Graph();
	graph->v=v;
	graph->e=e;
	graph->edge=new Edge[e];
		return graph;
}

int find(subset op[],int i)
{
	if(op[i].parent!=i)
		op[i].parent=find(op,op[i].parent);
	return op[i].parent;
}

void union1(subset op[],int x,int y)
{
	int xset=find(op,x);
	int yset=find(op,y);

	if(op[xset].rank<op[yset].rank)
		op[xset].parent=yset;
 	else if(op[xset].rank>op[yset].rank)
 		op[yset].parent=xset;
 	else
 	{
 		op[yset].parent=xset;
 		op[yset].rank++;
 	}

}


int comp(const void *a,const void *b)
{
	Edge* a1=(Edge*)a;
	Edge* b1=(Edge*)b;
	return a1->weight>b1->weight;
}


void mst(Graph *graph)
{
	int V=graph->v;
	int a=0,l=0;
	Edge res[V];
	qsort(graph->edge,graph->e,sizeof(graph->edge[0]),comp);
	subset *subsets=new subset[V];
	for(int k=0;k<V;k++)
	{
		subsets[k].parent=k;
		subsets[k].rank=0;
	}



while(a<V-1 && l <graph->e)
	{
		Edge op=graph->edge[l++];
		int f=find(subsets,op.src);
		int g=find(subsets,op.dest);
		if(f!=g)
		{
			res[a++]=op;
			union1(subsets,f,g);

		}



	}

for (int z = 0; z < a; ++z)  
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
    mst(graph);

}