#include<bits/stdc++.h>
using namespace std;
const int N=1e3+7;
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
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<"list is "<<i<<" : ";
    //     for(int val:adj[i])
    //     {
    //         cout<<val<<" ";
    //     }
    //     cout<<endl;
    // }
    // bool isCycle=false;
    // for(int i=1;i<=n;i++)
    // {
    //     if(visited[i]==true) continue;
    //     isCycle=isCycle | dfs(1,-1);
    // }
    // if(isCycle==true) cout<<"YES"<<endl;
    // else cout<<"NO"<<endl;
    if(dfs(1,-1))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}