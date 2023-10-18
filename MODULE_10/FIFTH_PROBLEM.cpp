#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pairr;
const int N=1e4+7;
vector<pairr> adj[N];
int n,m;


void print_list()
{
    for(int i=1;i<=n;i++)
    {
        cout<<"the list of the weighted graph "<<i<<" : ";
        for(auto val:adj[i])
        {
            cout<<"("<<val.first<<","<<val.second<<")"<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    print_list();
    return 0;
}