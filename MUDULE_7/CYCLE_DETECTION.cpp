#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
vector<int> adj[N];
bool visited[N];


bool dfs(int u,int p)
{
    bool cycleExists=false;
    visited[u]=true;
    for(int val:adj[u])
    {
        if(val==p) continue;
        if(visited[val]==true) return true;
        cycleExists=cycleExists | dfs(val,u);
    }
    return cycleExists;
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
    if(dfs(1,-1))
    {
        cout<<"cycle detected"<<endl;
    }
    else
    {
        cout<<"no cycles detected"<<endl;
    }
    return 0;
}
/*
5
5
1 2 
2 3
3 5
5 4
4 2
*/