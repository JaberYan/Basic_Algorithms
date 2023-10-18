#include<bits/stdc++.h>
using namespace std;
int main()
{
    int node,edge;
    cin>>node>>edge;
    int adj[node+1][node+1];
    for(int i=0;i<=node;i++)
    {
        for(int j=0;j<=node;j++)
        {
            adj[i][j]=0;
            if(i==j) adj[i][j]=1;
        }
    }
    while(edge--) 
    {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    for(int i=0;i<=node;i++)
    {
        for(int j=0;j<=node;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}