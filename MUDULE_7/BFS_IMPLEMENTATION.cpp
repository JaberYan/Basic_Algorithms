#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
vector<int> adj[N];
bool visited[N];
int level[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s]=true;
    level[s]=0;
    while(!q.empty())
    {
        //take a node from the queue and insert unvisited neighbors of that node
        int u=q.front();
        q.pop();
        //section 1:a node is being processed
        cout <<"visiting node:"<<u<<endl;
        for(int val:adj[u])
        {
            //section 2:child processing
            if(visited[val]==true) continue;
            q.push(val);
            visited[val]=true;
            level[val]=level[u]+1;
            //section 3:child processing
        }
        //section 4:same as section 1
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
        cout<<"list of "<<i<<" : ";
        for(int val:adj[i])
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    cout<<"************"<<endl;
    bfs(1);
    cout<<"************"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<"level of node "<<i<<" : "<<level[i]<<endl;
    }
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<"List "<<i<<" : ";
    //     for(int val:adj[i])
    //     {
    //         cout<<val<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}
/*
13
12
1 2
1 3
1 10
2 4
2 5
3 9
5 6
5 7
7 8
10 11
10 12
8 13
*/