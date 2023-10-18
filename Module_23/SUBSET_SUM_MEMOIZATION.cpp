#include<bits/stdc++.h>
using namespace std;

int memoization[1005][1005];

bool subset_sum(int n,int s,int a[])
{
    if(memoization[n][s]!=false) return memoization[n][s];
    if(n==0)
    {
        if(s==0) 
        { 
            return true;
        }
        else return false;
    }
    if(a[n-1]<=s)
    {
        bool op1 = subset_sum(n-1,s-a[n-1],a);
        bool op2 = subset_sum(n-1,s,a);
        memoization[n][s] = op1 or op2;
    }
    else
    {
        memoization[n][s] = subset_sum(n-1,s,a);
    }
    return memoization[n][s];
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int s;
    cin>>s;
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=s;j++)
    //     {
    //         memoization[i][j]=-1;
    //     }
    // }
    if(subset_sum(n,s,a))
    {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}