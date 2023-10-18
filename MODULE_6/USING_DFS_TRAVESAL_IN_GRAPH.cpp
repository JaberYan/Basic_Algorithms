#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int> adj[N];
bool visited[N];

void dfs(int u)
{
    visited[u]=true;
    cout<<"visited node:"<<u<<endl;
    //section 1:actios just after entering node u
    for(int v:adj[u])
    {
        //section 2 :actions before entering a new neighbor/child
        if(visited[v]==true) continue;
        dfs(v);
        //section 3:actions after exiting a neighbor
    }
    //section 4:actions before exiting node u
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
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<"Node"<<" "<<i<<" "<<":";
    //     for(int j:adj[i])
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    dfs(1);

    cout<<"visited array:"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<"node "<<i<<" status: "<<visited[i]<<endl;
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