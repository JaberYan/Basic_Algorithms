#include<bits/stdc++.h>
using namespace std;

int parent[1000];
int parentLevel[1000];

void dsu_set(int n)
{
    for(int i=0;i<=n;i++)
    {
        parent[i]=-1;
        parentLevel[1]=0;
    }
}

int dsu_find(int node)
{
    while(parent[node]!=-1)
    {
        node=parent[node];
    }
    return node;
}

void dsu_union(int u,int v)
{
    int leaderA=dsu_find(u);
    int leaderB=dsu_find(v);
    if(leaderA != leaderB)
    {
        if(parentLevel[leaderA]>parentLevel[leaderB])
        {
            parent[leaderB]=leaderB;
        }
        else if(parentLevel[leaderB]>parentLevel[leaderA])
        {
            parent[leaderA]=leaderB;
        }
        else
        {
            parent[leaderB]=leaderA;
            parentLevel[leaderA]++;
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    dsu_set(n);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        dsu_union(u,v);
    }
    cout<<dsu_find(4);
    return 0;
}