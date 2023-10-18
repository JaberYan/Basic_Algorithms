#include<bits/stdc++.h>
using namespace std;
const int N=1e3+8;
vector<int> adj[N];
bool visited[N];
int cc=0;
vector<int> v[N];

void dfs(int u)
{
    visited[u]=true;
    v[cc+1].push_back(u);
    for(int val:adj[u])
    {
        if(visited[val]==false) dfs(val);
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
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==true) continue;
        dfs(i);
        cc++;
    }
    cout<<cc<<endl;
    for(int i=1;i<=cc;i++)
    {
        cout<<"component "<<" : ";
        for(int val:v[i])
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
6
4
1 2
2 3
3 4
5 6
*/