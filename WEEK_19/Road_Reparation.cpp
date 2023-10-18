#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
const int N=1e5+5;
vector<pi> adj[N];
bool visited[N];

class Edge
{
    public:
        int u,v,w;
        Edge(int u,int v,int w)
        {
            this->u=u;
            this->v=v;
            this->w=w;
        }
};

class cmp
{
    public:
        bool operator()(Edge a,Edge b)
        {
            return a.w > b.w;
        }
};

void prims(int s,int n)
{
    priority_queue<Edge,vector<Edge>,cmp> pq;
    vector<Edge> edgelist;
    pq.push(Edge(s,s,0));
    int cnt=0;
    while(!pq.empty())    //o(e)
    {
        Edge parent=pq.top();
        pq.pop();
        int u = parent.u;
        int v = parent.v;
        int w = parent.w;
        if(visited[v]) continue;
        visited[v]=true;
        cnt++;
        edgelist.push_back(parent);
        for(pi val:adj[v])
        {
            if(!visited[val.first])
            {
                pq.push(Edge(v,val.first,val.second));    //log(v) node er bittite
            }
        }
    }
    edgelist.erase(edgelist.begin());
    long long sum=0;
    for(Edge val:edgelist)
    {
        sum+=(long long)(val.w);
    }
    if(cnt==n)
    {
        cout<<sum<<endl;
    }
    else
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
}

int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    prims(1,n);
    return 0;
}