#include<bits/stdc++.h>
using namespace std;

const int N=1e5+9;
vector<int> adj[N];
vector<bool> visited(N,false);
vector<int> level(N,0);
vector<int> parent(N,-1);
vector<int> uvalue;

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    visited[source]=true;
    level[source]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int val:adj[u])
        {
            if(visited[val]==true) continue;
            q.push(val);
            parent[val]=u;
            visited[val]=true;
            level[val]=level[u]+1;
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
        uvalue.push_back(u);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(uvalue.front());
    // cout<<level[n]<<endl;
    if (!visited[n]) 
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    vector<int> path;
    int curr=n;
    while(curr!=-1)
    {
        path.push_back(curr);
        curr=parent[curr];
    }
    cout<<path.size()<<endl;
    reverse(path.begin(),path.end());
    for(int val:path)
    {
        cout<<val<<" ";
    }
    return 0;
}