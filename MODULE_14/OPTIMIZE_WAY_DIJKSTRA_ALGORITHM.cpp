#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<pair<int, int>> v[N];
int dis[N];
bool vis[N];
void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, s});
    dis[s] = 0;
    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();
        int parentNode = parent.second;
        if (vis[parentNode])
        {
            continue;
        }
        vis[parentNode] = true;
        int parentCost = parent.first;
        for (int i = 0; i < v[parentNode].size(); i++)
        {
            pair<int, int> child = v[parentNode][i];
            int childNode = child.first;
            int childCost = child.second;
            if (parentCost + childCost < dis[childNode])
            {
                dis[childNode] = parentCost + childCost;
                pq.push({dis[childNode], childNode});
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << ": " << dis[i] << endl;
    }
    return 0;
}
//complexity O(n+elogn)

// #include<bits/stdc++.h>
// using namespace std;
// typedef pair<int,int> pairr;
// const int N=1e5+5;
// vector<pairr> adj[N];
// int dis[N];
// bool visited[N];

// void naive_dijkstra(int source)
// {
//     priority_queue<pairr,vector<pairr> ,greater<pairr>>q;
//     q.push({0,source});
//     dis[source]=0;
//     while(!q.empty())
//     {
//         pairr mini=q.top();
//         q.pop();
//         int parentNode=mini.second;
//         if(visited[parentNode]) continue;
//         visited[parentNode]=true;
//         int parentCost=mini.first;
//         for(int i=0;i<adj[parentNode].size();i++)
//         {
//             pairr child=adj[parentNode][i];
//             int childNode = child.first;
//             int childCost = child.second;
//             if(dis[childNode]>parentCost+childCost)
//             {
//                 dis[childNode]=parentCost+childCost;
//                 q.push({dis[childCost],childNode});
//             }
//         }
//     }
// }

// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     for(int i=0;i<m;i++)
//     {
//         int u,v,w;
//         cin>>u>>v>>w;
//         adj[u].push_back({v,w});
//         adj[v].push_back({u,w});
//     }
//     // for(int i=1;i<=n;i++)
//     // {
//     //     cout<<"The node edge is "<<i<<": ";
//     //     for(int j=0;j<adj[i].size();j++)
//     //     {
//     //         int val=adj[i][j].first;
//     //         int weight=adj[i][j].second;
//     //         cout<<"("<<val<<","<<weight<<")"<<" ";
//     //     }
//     //     cout<<endl;
//     // }
//     for(int i=0;i<=n;i++)
//     {
//         dis[i]=INT_MAX;
//     }
//     naive_dijkstra(1);
//     for(int i=1;i<=n;i++)
//     {
//         cout<<"Node "<<i<<": "<<dis[i]<<endl;
//     }
//     return 0;
// }

//complexity O(n+elogn)