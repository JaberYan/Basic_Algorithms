#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pairr;

const int N=1e5+7;
const int INF=1e9+9;
vector<pairr> adj[N];
vector<int> dist(N,INF);
vector<bool> visited(N);


void dijkstra(int source)
{
    priority_queue<pairr,vector<pairr>,greater<pairr>> pq;
    dist[source]=0;
    pq.push({dist[source],source});

    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();

        visited[u]=true;

        for(pairr valpair:adj[u])
        {
            int val=valpair.first;
            int weight=valpair.second;

            if(visited[val]) continue;

            if(dist[val]>dist[u]+weight)
            {
                dist[val]=dist[u]+weight;
                pq.push({dist[val],val});
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

    dijkstra(1);

    for(int i=1;i<=12;i++)
    {
        cout<<"Distance of Node "<<i<<" : "<<dist[i]<<endl;
    }
    return 0;
}