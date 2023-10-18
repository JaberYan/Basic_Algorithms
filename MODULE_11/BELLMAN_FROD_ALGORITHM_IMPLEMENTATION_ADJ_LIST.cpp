#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pairr;
const int N=1e5+9;
const int INF=1e9+10;
vector<pairr> adj[N];
int d[N];
int n,m;

void bellman_frod(int source)
{
    for(int i=1;i<=n;i++)
    {
        d[i]=INF;
    }
    d[source]=0;
    for(int i=1;i<n;i++)
    {
        //all edges relaxation
        for(int u=1;u<=n;u++)
        {
            for(pairr vpair:adj[u])
            {
                int v=vpair.first;
                int w=vpair.second;
                if(d[u]!=INF && d[v]>d[u]+w)
                {
                    d[v]=d[u]+w;
                }
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        // adj[v].push_back({u,w});
    }

    bellman_frod(1);

    for(int i=1;i<=n;i++)
    {
        cout<<"Distance of "<<i;
        cout<<" : "<<d[i]<<endl;
    }

    return 0;
}