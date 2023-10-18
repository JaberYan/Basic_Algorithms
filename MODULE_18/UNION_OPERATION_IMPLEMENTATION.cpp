#include<bits/stdc++.h>
using namespace std;

int parent[1000];

void dsu_set(int n)
{
    for(int i=0;i<=n;i++)
    {
        parent[i]=-1;
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
        parent[leaderB]=leaderA;
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
        int a=dsu_find(u);
        int b=dsu_find(v);
        if(a==b)
        {
            cout<<"Cycle detected between:"<<u<<" "<<v<<endl;
        }
        else
        {
            dsu_union(u,v);
        }
    }
    // cout<<dsu_find(5);
    return 0;
}