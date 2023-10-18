#include<bits/stdc++.h>
using namespace std;

int parent[1000];
int parentSize[1000];

void DSU_set(int n)
{
    for(int i=0;i<=n;i++)
    {
        parent[i]=-1;
        parentSize[1]=1;
    }
}

int DSU_find(int n)
{
    while(parent[n]!=-1)
    {
        n=parent[n];
    }
    return n;
}

void DSU_union(int a,int b)
{
    int leaderA=DSU_find(a);
    int leaderB=DSU_find(b);
    if(leaderA != leaderB)
    {
        if(parentSize[leaderA] > parentSize[leaderB])
        {
            parent[leaderB]=leaderA;
            parentSize[leaderA]+=parentSize[leaderB];
        }
        else
        {
            parent[leaderA]=leaderB;
            parentSize[leaderB]+=parentSize[leaderA];
        }
    }
}


int main()
{
    int n,m;
    cin>>n>>m;
    DSU_set(n);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        DSU_union(a,b);
    }
    cout<<DSU_find(7);
    return 0;
}