// #include<bits/stdc++.h>
// using namespace std;
// #define pi pair<int,int>
// const int N=1e5+5;
// vector<pi> adj[N];
// bool visited[N];

// class Edge
// {
//     public:
//         int u,v,w;
//         Edge(int u,int v,int w)
//         {
//             this->u=u;
//             this->v=v;
//             this->w=w;
//         }
// };

// class cmp
// {
//     public:
//         bool operator()(Edge a,Edge b)
//         {
//             return a.w > b.w;
//         }
// };

// void prims(int s)
// {
//     priority_queue<Edge,vector<Edge>,cmp> pq;
//     vector<Edge> edgelist;
//     pq.push(Edge(s,s,0));
//     while(!pq.empty())    //o(e)
//     {
//         Edge parent=pq.top();
//         pq.pop();
//         int u = parent.u;
//         int v = parent.v;
//         int w = parent.w;
//         if(visited[v]) continue;
//         visited[v]=true;
//         edgelist.push_back(parent);
//         for(pi val:adj[v])
//         {
//             if(!visited[val.first])
//             {
//                 pq.push(Edge(v,val.first,val.second));    //log(v) node er bittite
//             }
//         }
//     }
//     edgelist.erase(edgelist.begin());
//     for(Edge val:edgelist)
//     {
//         cout<<val.u<<" "<<val.v<<" "<<val.w<<endl;
//     }
// }

// int main()
// {
//     int n,e;
//     cin>>n>>e;
//     while(e--)
//     {
//         int u,v,w;
//         cin>>u>>v>>w;
//         adj[u].push_back({v,w});
//         adj[v].push_back({u,w});
//     }
//     prims(1);
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
const int N=1e5+5;
vector<pi> adj[N];
bool visited[N];

class Edge
{
    public:
        int u;
        int v;
        int w;
        Edge(int u,int v,int w)
        {
            this->u=u;
            this->v=v;
            this->w=w;
        }
};

class cmp
{
    public:
        bool operator()(Edge a,Edge b)
        {
            return a.w > b.w;
        }
};

void prims(int s)
{
    priority_queue<Edge,vector<Edge>,cmp> pq;
    pq.push(Edge(s,s,0));
    pq.push(Edge(7,8,9));
    vector<Edge> edgelist;
    while(!pq.empty())
    {
        Edge parent = pq.top();
        pq.pop();
        int u=parent.u;
        int v=parent.v;
        int w=parent.w;
        if(visited[v]) continue;
        visited[v]=true;
        edgelist.push_back(parent);
        for(pi val:adj[v])
        {
            if(!visited[val.first])
            {
                pq.push(Edge(v,val.first,val.second));
            }
        }
    }
    for(Edge val:edgelist)
    {
        cout<<val.u<<" "<<val.v<<" "<<val.w<<endl;
    }
}


// void prims(int s)
// {
//     priority_queue<Edge,vector<Edge>,cmp> pq;
//     vector<Edge> edgelist;
//     pq.push(Edge(s,s,0));
//     while(!pq.empty())    //o(e)
//     {
//         Edge parent=pq.top();
//         pq.pop();
//         int u = parent.u;
//         int v = parent.v;
//         int w = parent.w;
//         if(visited[v]) continue;
//         visited[v]=true;
//         edgelist.push_back(parent);
//         for(pi val:adj[v])
//         {
//             if(!visited[val.first])
//             {
//                 pq.push(Edge(v,val.first,val.second));    //log(v) node er bittite
//             }
//         }
//     }
//     edgelist.erase(edgelist.begin());
//     for(Edge val:edgelist)
//     {
//         cout<<val.u<<" "<<val.v<<" "<<val.w<<endl;
//     }
// }

int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    prims(1);
    return 0;
}

//total complexity V+ElogE
/*
8 11
1 2 4
1 5 2
1 4 10
2 3 18
2 4 8
5 4 5
3 4 11
4 8 9
4 7 11
8 6 2
7 6 1
*/