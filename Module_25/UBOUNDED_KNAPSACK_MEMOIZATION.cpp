#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;

int memoization[N][N];

int unbounded_knapsack(int n,int s,int v[],int w[])
{
    if(n==0 or s==0) return 0;
    if(memoization[n][s]!=-1) return memoization[n][s];
    if(w[n-1]<=s)
    {
        int op1 = unbounded_knapsack(n,s-w[n-1],v,w) + v[n-1];
        int op2 = unbounded_knapsack(n-1,s,v,w);
        return memoization[n][s] = max(op1,op2);
    }
    else
    {
        return memoization[n][s] = unbounded_knapsack(n-1,s,v,w);
    }
}

int main()
{
    int n,sum;
    cin>>n>>sum;
    int value[n],weight[n];
    for(int i=0;i<n;i++)
    {
        cin>>value[i];
    }

    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }

    memset(memoization,-1,sizeof(memoization));

    cout<<unbounded_knapsack(n,sum,value,weight)<<endl;
    return 0;
}