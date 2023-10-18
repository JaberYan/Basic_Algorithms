#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int dis[N][N];

class Edge
{
    public:
        int u;
        int v;
        int w;
        int c;
        Edge(int u,int v,int w,int c)
        {
            this->u=u;
            this->v=v;
            this->w=w;
            this->c=c;
        }
};

int main()
{
    int n;
    cin>>n;
    vector<Edge> adj;
    for(int i=0;i<n;i++)
    {
        int u,v,w,c;
        cin>>u>>v>>w>>c;
        Edge ed(u,v,w,c);
        // cout<<ed.u<<" "<<ed.v<<" "<<ed.w<<" "<<ed.c<<endl;
        adj.push_back(ed);
    }
    for(int i=0;i<adj.size();i++)
    {
        Edge ed=adj[i];
        int u=ed.u;
        int v=ed.v;
        int w=ed.w;
        int c=ed.c;
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                dis[j][k]=u;
                dis[j][k+1]=v;
                dis[j][k+2]=w;
                dis[j][k+3]=c;
                break;
            }
        }
    }
    for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                cout<<dis[j][k]<<" ";
            }
            cout<<endl;
        }
    
    return 0;
}