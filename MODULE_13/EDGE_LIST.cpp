#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> o;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v; 
        o.push_back({u,v});
    }
    for(int i=0;i<o.size();i++)
    {
        cout<<"("<<o[i].first<<","<<o[i].second<<")"<<endl;
    }
    return 0;
}