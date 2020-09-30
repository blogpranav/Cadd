#include<iostream>
#include<list>
#include<bits/stdc++.h> 
using namespace std;

class graph{
	int v;
	list <int> *adj;
public:

	graph(int v)
	{
		this->v=v;
		adj=new list <int>[v];
	}

	void addEdge(int o,int w)
	{
		adj[o].push_back(w);
	}
	bool cyclicutil(int x,bool visited[],bool recstack[])
	{
		if(visited[x]==false)
		{
		visited[x]=true;
		recstack[x]=true;

		list<int>::iterator i;
		for(i=adj[x].begin();i!=adj[x].end();++i)
		{
			if(!visited[*i]&& cyclicutil(*i,visited,recstack))
				return true;
			else if(recstack[*i])
				return true;

		}
		
		}
		recstack[x]=false;
		return false;

	}

	bool cyclic()
	{
		bool *visited= new bool[v];
		bool *recstack= new bool[v];
		for(int i=0;i<v;i++)
		{
			visited[i]=false;
			recstack[i]=false;

			
			}


			for(int i=0;i<v;i++)
			{
					if(cyclicutil(i,visited,recstack))
						return true;

			}
			return false;
		}


};
int main()
{


	 graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    if(g.cyclic()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 
    return 0; 
}