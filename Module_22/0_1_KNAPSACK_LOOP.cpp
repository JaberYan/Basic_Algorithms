#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int v[n],w[n];
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }

    int s;
    cin>>s;

    int ans[n+1][s+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            if(i==0 or j==0) ans[i][j]=0;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(w[i-1]<=j)
            {
                // int choice1 = ans[i-1][j-w[i-1]] + v[i-1];
                // int choice2 = ans[i-1][j];
                // ans[i][j] = max(choice1,choice2);
                ans[i][j] = max(ans[i-1][j-w[i-1]]+v[i-1],ans[i-1][j]);
            }
            else
            {
                ans[i][j] = ans[i-1][j];
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}