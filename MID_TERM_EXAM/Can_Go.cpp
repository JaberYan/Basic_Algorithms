#include <bits/stdc++.h>
using namespace std;
typedef pair<long long int,long long int> pii;
const int N=1005;
const long long int INF = 1e12+5;
vector<pii> v[N];
long long int dis[N];
bool vis[N];

void dijkstra(int s) 
{
    priority_queue<pii,vector<pii>,greater<pii>> pq;

    pq.push({0,s});
    dis[s]=0;

    while (!pq.empty()) 
    {
        pii parent=pq.top();
        pq.pop();
        int parentNode=parent.second;

        if (vis[parentNode]) 
        {
            continue;
        }

        vis[parentNode]=true;
        int parentCost=parent.first;

        for (pii child:v[parentNode]) 
        {
            int childNode=child.first;
            int childCost=child.second;

            if (dis[parentNode]+childCost<dis[childNode]) 
            {
                dis[childNode]=dis[parentNode]+childCost;
                pq.push({dis[childNode],childNode});
            }
        }
    }
}

int main() 
{
    int n,e;
    cin>>n>>e;

    while (e--) 
    {
        int a,b,w;
        cin>>a>>b>>w;
        v[a].push_back({b,w});
        // v[b].push_back({a,w});
    }

    int source;
    cin>>source;

    int t;
    cin>>t;
    for (int i=0;i<=n;i++) 
        {
            dis[i]=INF;
            vis[i]=false;
        }

    dijkstra(source);

    while (t--) 
    {
        int ds,dw;
        cin>>ds>>dw;


        if (dis[ds]<=dw) 
        {
            cout<<"YES"<<endl;
        } 
        else 
        {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;
// typedef pair<int,int> pairr;
// const int N=1e5+9;
// const int INF=1e9+10;
// vector<pairr> adj[N];
// long long int d[N];
// int n,m;

// void bellman_frod(int source)
// {
//     for(int i=1;i<=n;i++)
//     {
//         d[i]=INF;
//     }
//     d[source]=0;
//     for(int i=1;i<n;i++)
//     {
//         //all edges relaxation
//         for(int u=1;u<=n;u++)
//         {
//             for(pairr vpair:adj[u])
//             {
//                 int v=vpair.first;
//                 int w=vpair.second;
//                 if(d[u]!=INF && d[v]>d[u]+w)
//                 {
//                     d[v]=d[u]+w;
//                 }
//             }
//         }
//     }
// }
// int main()
// {
//     cin>>n>>m;
//     for(int i=0;i<m;i++)
//     {
//         int u,v,w;
//         cin>>u>>v>>w;
//         adj[u].push_back({v,w});
//         adj[v].push_back({u,w});
//     }

//     int source;
//     cin>>source;
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int ds,dw;
//         cin>>ds>>dw;

//         bellman_frod(source);

        
//             if(d[ds]<=dw)
//             {
//                 cout<<"YES"<<endl;
//             }
//             else
//             {
//                 cout<<"NO"<<endl;
//             }
//     }

//     return 0;
// }