#include<bits/stdc++.h>
using namespace std;
const int N=1e5;

int parent[N];
int parentSize[N];

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
    int sum=0;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        int leaderA=DSU_find(a);
        int leaderB=DSU_find(b);
        if(leaderA==leaderB)
        {
            sum++;
        }
        else
        {
            DSU_union(a,b);
        }
    }
    cout<<sum<<endl;
    return 0;
}