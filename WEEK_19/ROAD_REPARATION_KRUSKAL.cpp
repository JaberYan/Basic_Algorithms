#include<bits/stdc++.h>
using namespace std;

class Edge
{
    public:
        int u;
        int v;
        int w;
        Edge (int u,int v,int w)
        {
            this->u=u;
            this->v=v;
            this->w=w;
        }
};

bool cmp(Edge a,Edge b)
{
    return a.w < b.w;
}

const int N=1e5+5;
int parent[N];
int parentSize[N];

void DSU_set(int n)
{
    for(int i=0;i<=n;i++)
    {
        parent[i]=-1;
        parentSize[1]=1;
    }
}

int DSU_find(int n)
{
    while(parent[n]!=-1)
    {
        n=parent[n];
    }
    return n;
}

void DSU_union(int a,int b)
{
    int leaderA=DSU_find(a);
    int leaderB=DSU_find(b);
    if(leaderA != leaderB)
    {
        if(parentSize[leaderA] > parentSize[leaderB])
        {
            parent[leaderB]=leaderA;
            parentSize[leaderA]+=parentSize[leaderB];
        }
        else
        {
            parent[leaderA]=leaderB;
            parentSize[leaderB]+=parentSize[leaderA];
        }
    }
}

int main()
{
    int n,e;
    cin>>n>>e;
    vector<Edge> adj;
    vector<Edge> ans;
    DSU_set(n);
    while(e--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj.push_back(Edge(u,v,w));
    }
    sort(adj.begin(),adj.end(),cmp);
    for(Edge val:adj)
    {
        int u=val.u;
        int v=val.v;
        int w=val.w;
        int leaderA = DSU_find(u);
        int leaderB = DSU_find(v);
        if(leaderA==leaderB) continue;
        ans.push_back(val);
        DSU_union(u,v);
    }
    long long sum=0;
    for(Edge val:ans)
    {
        sum+=(long long)val.w;
    }
    if(ans.size()==n-1)
    {
        cout<<sum<<endl;
    }
    else
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
//complexity o(ElogE)