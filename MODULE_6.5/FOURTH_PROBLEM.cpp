#include<bits/stdc++.h>
using namespace std;
const int N=1e3+7;
bool visited[N];
vector<int> adj[N];
int depth[N];
void dfs(int u)
{
    visited[u]=true;
    for(int v:adj[u])
    {
        if(visited[v]==true) continue;
        depth[v]=depth[u]+1;
        dfs(v);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int x;
    cin>>x;
    // cout<<x;
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        if(i==x)
        {
            cout<<"Depth of "<<i<<" = "<<depth[i];
        }
    }
    return 0;
}