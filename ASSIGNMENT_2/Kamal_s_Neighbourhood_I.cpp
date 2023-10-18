#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
vector<int> adj[N];

int main() 
{
    int n,m;
    cin>>n>>m;
    
    for (int i=0;i<m;i++) 
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int k;
    cin>>k;
    
    int connect=adj[k].size();
    cout<<connect<<endl;
    
    return 0;
}
