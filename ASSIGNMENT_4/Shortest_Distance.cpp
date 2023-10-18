#include<bits/stdc++.h>
using namespace std;
const int N=1e3+4;
const long long int INF=1e18;
long long int d[N][N];
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

    while(m--)
    {
        long long int u,v,w;
        cin>>u>>v>>w;
        d[u][v]=min(d[u][v],w);
        // d[v][u]=w;
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

    // print_matrix();
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(d[a][b]==INF)
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<d[a][b]<<endl;
        }
    }
    return 0;
}