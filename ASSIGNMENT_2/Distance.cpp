#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adj[N];
int level[N];
int visited[N];


void bfs(int s) 
{
    queue<int> q;
    q.push(s);
    visited[s]=1;
    level[s] = 0;

    while (!q.empty()) 
    {
        int u=q.front();
        q.pop();
        for (int v:adj[u]) 
        {
            if (visited[v]!=0) continue;
            q.push(v);
            visited[v]=1;
            level[v]=level[u]+1;
            
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int q;
    cin>>q;

    while (q--) 
    {
        int u,k;
        cin>>u>>k;

        for (int i=0;i<N;i++)
        {
            visited[i]=0;
        }
        bfs(u);
        if (visited[k]==0) 
        {
            cout<<-1<<endl;
        } 
        else 
        {
            cout<<level[k]<<endl;
        }
    }
    return 0;
}