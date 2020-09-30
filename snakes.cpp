#include <bits/stdc++.h>

using namespace std;

// Complete the quickestWayUp function below.
class node{
    public:
    int w;
    int weight;
    node(int w,int weight)
    {
        this->w=w;
        this->weight=weight;
    }
};
class graph{
    public:
    int v;
    list <node>*adj;
    graph(int v)
    {
        this->v=v;
        adj=new list<node>[v+1];
    }
    void addedge(int v,int w,int weight)
    {
        node n(w,weight);
        adj[v].push_back(n);
    }

    int bfs(int s)
    {
        bool *visited=new bool[v+1];
        for(int i=1;i<=v;i++)
        visited[i]=false;
        visited[s]=true;
        list <node> queue;
        node n(0,0);
        //queue.push_back(n);
        int dice=0;
        int flag=1;
        int count=0;
        do
        {
            cout<<"in while"<<endl;
            if(flag!=1)
            
            {
            node x=queue.front();
            queue.pop_front(); 
             count+=x.weight;
             list <node>::iterator i;
             for(i=adj[x.w].begin();i!=adj[x.w].end();i++)
             {
                cout<<"in if for"<<endl;
                 node l=*i;
                 if(!visited[l.w])
                 {
                     visited[l.w]=true;
                     queue.push_back(l);
                 }
             }
            }  
            else 
            {
                flag=0;
                list <node>::iterator i;
             for(i=adj[1].begin();i!=adj[1].end();i++)
             {
                cout<<"in else for"<<endl;
                 node l=*i;
                 if(!visited[l.w])
                 {
                     visited[l.w]=true;
                     queue.push_back(l);
                 }
             }
            }
        }while(!queue.empty());

                    
         return count;   
        }
    };
    

int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    graph g(100);
    int arr[101];
    for(int i=1;i<101;i++)
    arr[i]=i;
    for(int i=0;i<ladders.size();i++)
    {
        arr[ladders[i][0]]=ladders[i][1];
    }
    for(int i=0;i<snakes.size();i++)
    {
        arr[snakes[i][0]]=snakes[i][1];
    }
    for(int i=1;i<101;i++)
    {
        for(int j=6;j>=1;j--)
        g.addedge(i,arr[i+j],j);
    }
    //cout<<"before cfs";
   int x= g.bfs(1);
   return x;


}

int main()
{
    vector <vector<int> >ladders {{32, 62},
                            {42 ,68},
                                {12, 98}};
    vector <vector<int>> snakes {{95, 13},
{97 ,25},
{93 ,37},
{79 ,27},
{75 ,19},
{49 ,47},
{67, 17}  };
int x=quickestWayUp(ladders,snakes);
cout<<x;

    return 0;
}
