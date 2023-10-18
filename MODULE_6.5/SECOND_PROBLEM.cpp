#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector<int> adj2[N];
int adj[N][N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>adj[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(adj[i][j]==1)
            {
                adj2[i].push_back(j);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<"List "<<i<<" : ";
        for(int v:adj2[i])
        {
            cout<<v<<" ";
        }
        cout<<endl;
    }
    return 0;
}