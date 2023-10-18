#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
vector<int> adj[N];
bool visited[N];

void dfs(int node) 
{
    visited[node]=true;
    for (int neighbor:adj[node]) 
    {
        if(visited[neighbor]==true) continue;
        dfs(neighbor);
    }
}
int main() 
{
    int n,m;
    cin>>n>>m;

    for (int i=0;i<m;i++) 
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    int k;
    cin>>k;

    dfs(k);

    int cnthouse=0;
    for (int i=0;i<n;i++) 
    {
        if (visited[i]==true) 
        {
            cnthouse++;
        }
    }
    cout<<cnthouse-1<<endl;
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e4+7;
// vector<int> adj[N];

// int main() 
// {
//     int n,m;
//     cin>>n>>m;
    
//     for (int i=0;i<m;i++) 
//     {
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//     }

//     int k;
//     cin>>k;
    

//     // for(int i=0;i<k;i++)
//     // {
//              for(int val:adj[k])
//              {
//                  cout<<val<<" ";
//              }
//        }
    
//     return 0;
// }
