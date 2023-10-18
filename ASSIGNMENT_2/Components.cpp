#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
vector<int> adj[N];
bool visited[N];
vector<int> v[N];
int cc=0;


void dfs(int u)
{
    visited[u]=true;
    v[cc+1].push_back(u);
    for(int val:adj[u])
    {
        if(visited[val]==true) continue;
        dfs(val);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);    
        adj[v].push_back(u);    
    }
    for(int i=0;i<=N;i++)
    {
        if(visited[i]==true) continue;
        dfs(i);
        cc++;
    }
    // cout<<"number of connected components:"<<cc<<endl;
    vector<int> vv;
    for(int i=1;i<=cc;i++)
    {
        vv.push_back(v[i].size());
    }
    sort(vv.begin(),vv.end());
    for(int val:vv)
    {
        if(val>1)
        {
            cout<<val<<" ";
        }
    }
    return 0;
}



// #include <bits/stdc++.h>
// using namespace std;

// const int N=1e4+9;

// vector<int> adj[N];
// vector<bool> visited(N);

// int dfs(int node)
// {
//     visited[node] = true;
//     int size = 1;
//     for (int v : adj[node])
//     {
//         if (!visited[v])
//         {
//             size += dfs(v);
//         }
//     }
//     return size;
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     for (int i = 0; i < m; ++i)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     vector<int> componentSizes;

//     for (int i = 0; i <=1000; ++i)
//     {
//         if (!visited[i])
//         {
//             int size = dfs(i);
//             if (size > 1)
//             {
//                 componentSizes.push_back(size);
//             }
//         }
//     }

//     sort(componentSizes.begin(), componentSizes.end());

//     for (int size : componentSizes)
//     {
//         cout << size << " ";
//     }
//     cout << endl;

//     return 0;
// }