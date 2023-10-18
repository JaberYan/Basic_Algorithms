#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> adj[N];
int dis[N];
bool visited[N];

void dfs(int source)
{
    visited[source]=true;
    cout<<source<<endl;
    for(int i=0;i<adj[source].size();i++)
    {
        int child=adj[source][i];
        if(visited[child]==true) continue;
        // visited[child]=true;
        dis[child]=dis[source]+1;
        dfs(child);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        cout<<"Node "<<i<<": "<<dis[i]<<endl;
    }
    return 0;
}