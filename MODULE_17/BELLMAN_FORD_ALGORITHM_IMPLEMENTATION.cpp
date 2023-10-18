#include<bits/stdc++.h>
using namespace std;
class Edge
{
    public:
        int u;
        int v;
        int w;

        Edge(int u,int v,int w)
        {
            this->u=u;
            this->v=v;
            this->w=w;
        }
};

int main()
{
    int n,e;
    cin>>n>>e;
    vector<Edge> va;
    while(e--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        Edge ed(u,v,w);
        // cout<<ed.u<<" "<<ed.v<<" "<<ed.w<<endl;
        va.push_back(ed);
    }

    int dis[n+1];
    for(int i=1;i<=n;i++)
    {
        dis[i]=INT_MAX;
    }

    dis[1]=0;

    for(int i=1;i<=n-1;i++)
    {
        for(int j=0;j<va.size();j++)
        {
            Edge ed=va[j];
            int u=ed.u;
            int v=ed.v;
            int w=ed.w;
            // if(dis[ed.v]>dis[ed.u]+ed.w) dis[ed.v]=dis[ed.u]+ed.w; //otherwise
            if(dis[u]+w<dis[v]) dis[v]=dis[u]+w;
            // if(dis[v]>dis[u]+w) dis[v]=dis[u]+w;//otherwise
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<"Node "<<i<<": "<<dis[i]<<endl;
    }
    return 0;
}