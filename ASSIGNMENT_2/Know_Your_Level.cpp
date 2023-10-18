#include <bits/stdc++.h>
using namespace std;
const int N=1e5+1;

int main()
{
    int n,E;
    cin>>n>>E;

    vector<vector<int>> adj(N+1);
    for (int i=0;i<E;i++)
    {
        int A,B;
        cin>>A>>B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    int L;
    cin>>L;

    queue<int> q;
    q.push(0);
    vector<int> level(N+1,-1);
    level[0]=0;

    while (!q.empty())
    {
        int curr=q.front();
        q.pop();

        for (int next:adj[curr])
        {
            if (level[next]==-1)
            {
                level[next]=level[curr]+1;
                q.push(next);
            }
        }
    }
    set<int> shopsInLevelL;
    for (int i=0;i<=N;i++)
    {
        if (level[i]==L)
        {
            shopsInLevelL.insert(i);
        }
    }
    if (L==0)
        cout<<0<<" ";
    else if (shopsInLevelL.empty())
    {
        cout<<"-1";
    }
    else
    {
        for (int shop:shopsInLevelL)
        {
            cout<<shop<<" ";
        }
        cout<<endl;
    }
    return 0;
}