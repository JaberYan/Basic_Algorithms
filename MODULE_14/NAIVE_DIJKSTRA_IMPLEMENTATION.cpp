#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pairr;
const int N=1e5+5;
const int INF=1e9+5;
vector<pairr> adj[N];
int dis[N];

void naive_dijkstra(int source)
{
    queue<int> q;
    q.push(source);
    dis[source]=0;
    while(!q.empty())
    {
        int parent=q.front();
        q.pop();
        for(int i=0;i<adj[parent].size();i++)
        {
            pairr child=adj[parent][i];
            int childNode = child.first;
            int childCost = child.second;
            if(dis[childNode]>dis[parent]+childCost)
            {
                dis[childNode]=dis[parent]+childCost;
                q.push(childNode);
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
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<"The node edge is "<<i<<": ";
    //     for(int j=0;j<adj[i].size();j++)
    //     {
    //         int val=adj[i][j].first;
    //         int weight=adj[i][j].second;
    //         cout<<"("<<val<<","<<weight<<")"<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<N;i++)
    {
        dis[i]=INT_MAX;
    }
    naive_dijkstra(1);
    for(int i=1;i<=n;i++)
    {
        cout<<"Node "<<i<<": "<<dis[i]<<endl;
    }
    return 0;
}

//complexity O(n x e)