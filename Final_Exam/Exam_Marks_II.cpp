#include<bits/stdc++.h>
using namespace std;

int memoization[1005][1005];

bool subset_sum(int n,int s,int a[])
{
    if(n==0)
    {
        if(s==0) return true;
        else return false;
    }

    if(memoization[n][s]!=-1) return memoization[n][s];
    
    if(a[n-1]<=s)
    {
        bool op1 = subset_sum(n,s-a[n-1],a);
        bool op2 = subset_sum(n-1,s,a);
        memoization[n][s] = op1 || op2;
    }
    else
    {
        memoization[n][s] = subset_sum(n-1,s,a);
    }
    return memoization[n][s];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,s;
        cin>>n>>s;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        memset(memoization,-1,sizeof(memoization));
        int target = 1000-s;
        if(subset_sum(n,target,a))
        {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}