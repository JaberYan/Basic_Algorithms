#include<bits/stdc++.h>
using namespace std;
const int N=1e3+4;
const int INF=1e9+5;
int d[N][N];
int n,m;

void initialize()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            d[i][j]=INF;
        }
    }
}

void print_matrix()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(d[i][j]==INF) cout<<'X'<<" ";
            else cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    cin>>n>>m;

    initialize();
    // print_matrix();
    // cout<<endl;

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        d[u][v]=w;
    }

    // print_matrix();

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(d[i][j]>d[i][k]+d[k][j])
                {
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
    }

    print_matrix();

    return 0;
}