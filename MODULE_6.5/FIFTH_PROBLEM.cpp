#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int> adj[N];
bool visited[N];
int height[N];
int depth[N];
void dfs(int u)
{
    visited[u]=true;
    for(int v:adj[u])
    {
        if(visited[v]==true) continue;
        depth[v]=depth[u]+1;
        dfs(v);
        // if(height[v]+1>height[u])
        // {
        //     height[u]=height[v]+1;
        // }
        height[u]=max(height[u],height[v]+1); //otherwish
    }
}
int main()
{
    int n,m;
    cin>> n >>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int x;
    cin>>x;
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        if(i==x)
        {
            cout<<"Height of "<<i<<" : "<<height[i]<<endl;
        }
    }
    return 0;
}
//tree
// 10
// 9
// 1 2
// 1 3
// 1 10
// 2 4 
// 3 5
// 3 6
// 4 7 
// 4 8
// 6 9 