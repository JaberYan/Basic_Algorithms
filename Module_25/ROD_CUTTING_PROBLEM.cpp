#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;

int memoization[N][N];

int unvbounded_knapsack(int n,int s,int v[],int w[])
{
    if(n==0 or s==0) return 0;
    if(memoization[n][s]!=-1) return memoization[n][s];
    if(w[n-1]<=s)
    {
        return memoization[n][s] = max(v[n-1]+unvbounded_knapsack(n,s-w[n-1],v,w),unvbounded_knapsack(n-1,s,v,w));
    }
    else
    {
        return memoization[n][s] = unvbounded_knapsack(n-1,s,v,w);
    }
}
int main()
{
    int n;
    cin>>n;
    int value[n];
    int weight[n];
    for(int i=0;i<n;i++)
    {
        cin>>value[i];
        weight[i]=i+1;
    }

    memset(memoization,-1,sizeof(memoization));

    cout<<unvbounded_knapsack(n,n,value,weight)<<endl;

    return 0;
}