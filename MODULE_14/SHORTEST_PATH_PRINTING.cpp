#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> adj[N];
bool visited[N];
vector<int> parent(N); 
int dis[N];


void bfs(int source)
{
    visited[source]=true;
    queue<int> q;
    q.push(source);
    parent[source]=0;
    dis[source]=0;
    while(!q.empty())
    {
        int pare=q.front();
        q.pop();
        for(int val:adj[pare])
        {
            if(visited[val]==false)
            {
                visited[val]=true;
                parent[val]=pare;
                dis[val]=dis[pare]+1;
                q.push(val);
            }
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
    bfs(1);
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<"parent of "<<i<<": "<<parent[i]<<endl;
    //     cout<<"distance of "<<i<<" :"<<dis[i]<<endl;
    //     cout<<endl;
    // }
    int d;
    cin>>d;
    if(visited[d]==true)
    {
        vector<int> path;
        int x=d;
        while(x!=0)
        {
            // cout<<x<<endl;
            path.push_back(x);
            x=parent[x];
        }
        reverse(path.begin(),path.end());
        for(int val:path)
        {
            cout<<val<<endl;
        }
    }
    else
    {
        cout<<"Path Nai"<<endl;
    }
    return 0;
}