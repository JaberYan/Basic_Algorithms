#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
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
        dp[0][0] = 1;
        for(int i=1;i<=cur;i++) 
        {
            dp[0][i] = 0;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=cur;j++)
            {
                if(w[i-1]<=j)
                {
                    dp[i][j] = (dp[i][j-w[i-1]]+dp[i-1][j])%MOD;
                }
                else
                {
                    dp[i][j] = dp[i-1][j]%MOD;
                }
            }
        }
        cout<<dp[n][cur]<<endl;
    }
    return 0;
}