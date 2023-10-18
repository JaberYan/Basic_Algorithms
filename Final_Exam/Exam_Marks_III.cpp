#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,s;
        cin>>n>>s;
        int cur=1000-s;
        int w[n];
        for(int i=0;i<n;i++)
        {
            cin>>w[i];
        }
        dp[0][0] = 0;
        for(int i=1;i<=cur;i++) 
        {
            dp[0][i] = INT_MAX-1;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=cur;j++)
            {
                if(w[i-1]<=j)
                {
                    dp[i][j] = min(dp[i][j-w[i-1]]+1,dp[i-1][j]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[n][cur]==INT_MAX-1) cout<<-1<<endl;
        else cout<<dp[n][cur]<<endl;
    }
    return 0;
}