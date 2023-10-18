#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
vector<int> adj[N];
vector<bool> visited(N,false);

void dfs(int u)
{
    visited[u]=true;
    for(int val:adj[u])
    {
        if(visited[val]) continue;
        dfs(val);
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

    vector<int> leaders;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]) continue;
        leaders.push_back(i);
        dfs(i);
    }
    cout<<"0"<<" "<<"1"<<" "<<"2"<<" "<<"3"<<endl;
    for(auto val:leaders)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    cout<<leaders.size()-1<<endl;
    for(long unsigned int i=1;i<leaders.size();i++)
    {
        // cout<<leaders[i]<<" "<<leaders[i+1]<<endl;
        cout<<leaders[i-1]<<" "<<leaders[i]<<endl;
    }
    return 0;
}