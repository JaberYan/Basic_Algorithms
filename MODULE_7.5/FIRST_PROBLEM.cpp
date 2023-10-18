#include<bits/stdc++.h>
using namespace std;
const int N=1e3+7;
vector<int> adj[N];
bool visited[N];
void bfs(int s)
{
    vector<int> v2;
    visited[s]=true;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        visited[u]=true;
        v2.push_back(u);
        for(int child:adj[u])
        {
            if(visited[child]==true) continue;
            // visited[child]=true;
            q.push(child);
        }
    }
    reverse(v2.begin(),v2.end());
    for(int val:v2)
    {
        cout<<val<<" ";
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    stack<int> s;
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
    bfs(1);
    return 0;
}
/*
4 
4
1 2
3 4
1 3
2 4
*/