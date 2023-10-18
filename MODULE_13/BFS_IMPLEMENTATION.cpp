#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> adj[N];
int dis[N];
bool visited[N];

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    visited[source]=true;
    dis[source]=0;
    while(!q.empty())
    {
        int parent=q.front();
        q.pop();
        cout<<parent<<endl;
        for(int i=0;i<adj[parent].size();i++)
        {
            
            int child=adj[parent][i];
            if(visited[child]==false)
            {
                q.push(adj[parent][i]);
                visited[child]=true;
                dis[child]=dis[parent]+1;
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    for(int i=1;i<=n;i++)
    {
        cout<<"Node "<<i<<": "<<dis[i]<<endl;
    }
    return 0;
}