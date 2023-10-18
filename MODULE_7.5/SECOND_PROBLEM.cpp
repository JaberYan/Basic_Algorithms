#include<bits/stdc++.h>
using namespace std;
const int N=1e3+7;
vector<int> adj[N];
bool visited[N];
int level[N];

void bfs(int s)
{
    visited[s]=true;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int child:adj[u])
        {
            level[child]=level[u]+1;
            if(visited[child]==true) continue;
            q.push(child);
            visited[child]=true;
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
    int x;
    cin>>x;
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<"list is "<<i<<" : ";
    //     for(int val:adj[i])
    //     {
    //         cout<<val<<" ";
    //     }
    //     cout<<endl;
    // }
    bfs(1);
    for(int i=1;i<=n;i++)
    {
        if(level[i]==1)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}