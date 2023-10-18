#include<bits/stdc++.h>
using namespace std;
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
    bool ans[n+1][s+1];
    ans[0][0]=true;
    for(int i=1;i<=s;i++)
    {
        ans[0][i]=false;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            if(a[i-1]<=j)
            {
                bool op1 = ans[i-1][j-a[i-1]];
                bool op2 = ans[i-1][j];
                ans[i][j] = op1 or op2;
                // ans[i][j] = ans[i-1][j-a[i-1]] or ans[i-1][j];
            }
            else
            {
                ans[i][j] = ans[i-1][j];
            }
        }
    }

    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=s;j++)
    //     {
    //         if(ans[i][j]) cout<<"T ";
    //         else cout<<"F ";
    //     }
    //     cout<<endl;
    // }
    // if(ans[n][s]) cout<<"YES"<<endl;
    // else cout<<"NO"<<endl;
    return 0;
}