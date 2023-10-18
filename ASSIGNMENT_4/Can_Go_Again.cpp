#include<bits/stdc++.h>
using namespace std;

const long long int INF = 1e18;
const int N = 1005;

long long dist[N][N];

int main() 
{
    int n, e;
    cin >> n >> e;

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    for (int i = 0; i < e; i++) 
    {
        long long int u, v;
        long long int w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    for (int k = 1; k <= n; k++) 
    {
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
                // dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) 
    {
        if (dist[i][i] < 0) 
        {
            cout << "Negative Cycle Detected" << endl;
            return 0;
        }
    }

    int s;
    cin >> s;

    int t;
    cin >> t;

    while(t--)
    {
        int d;
        cin >> d;
        if (dist[s][d] == INF) 
        {
            cout << "Not Possible" << endl;
            // cout << dist[s][a] << endl;
        } 
        else 
        {
            cout << dist[s][d] << endl;
            // cout << "Not Possible" << endl;
        }
    }
    return 0;
}