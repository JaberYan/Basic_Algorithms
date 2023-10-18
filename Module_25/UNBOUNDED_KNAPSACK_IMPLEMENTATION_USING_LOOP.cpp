#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,s;
    cin>>n>>s;
    int dp[n+1][s+1];
    int value[n],weight[n];
    for(int i=0;i<n;i++)
    {
        cin>>value[i];
    }

    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            if(i==0 or j==0) dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(weight[i-1]<=j)
            {
                dp[i][j] = max(value[i-1]+dp[i][j-weight[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<dp[n][s]<<endl;

    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=s;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}