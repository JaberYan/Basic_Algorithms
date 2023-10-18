#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
vector<int> adj[N];
bool visited[N];
vector<int> v[N];


void dfs(int u)
{
    visited[u]=true;
    for(int val:adj[u])
    {
        if(visited[val]==true) continue;
        dfs(val);
    }
}
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int val:adj[u])
        {
            if(visited[val]==true) continue;
            q.push(val);
            visited[val]=true;
        }
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
    int cc=0;
    for(int i=1;i<=1000;i++)
    {
        if(visited[i]==true) continue;
        dfs(i);
        cc++;
    }
    cout<<"number of connected components:"<<cc<<endl;
    // for(int i=1;i<=cc;i++)
    // {
    //     cout<<"Component "<<i<<" : ";
    //     for(int val:v[i])
    //     {
    //         cout<<val<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}