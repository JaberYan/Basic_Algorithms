#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pairr;
const int N=1e5+8;
const int INF=1e9+10;
vector<pair<pairr, int>> list_of_edges;
int n,m;
int d[N];


void bellman_ford(int source)
{
    for(int i=1;i<=n;i++)
    {
        d[i]=INF;
    }
    d[source]=0;

    for(int i=1;i<n;i++)
    {
        for(auto edge:list_of_edges)
        {
            int u=edge.first.first;
            int v=edge.first.second;
            int w=edge.second;
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
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
        list_of_edges.push_back({{u,v},w});
    }

    bellman_ford(1);    

    for(int i=1;i<=n;i++)
    {
        cout<<"Distance of "<<i;
        cout<<" : "<<d[i]<<endl;
    }
    return 0;
}