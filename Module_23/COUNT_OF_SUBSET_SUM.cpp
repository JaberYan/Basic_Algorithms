// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     int s;
//     cin>>s;
//     int ans[n+1][s+1];
//     ans[0][0]=1;
//     for(int i=1;i<=s;i++)
//     {
//         ans[0][i]=0;
//     }

//     for(int i=1;i<=n;i++)
//     {
//         for(int j=0;j<=s;j++)
//         {
//             if(a[i-1]<=j)
//             {
//                 int op1 = ans[i-1][j-a[i-1]];
//                 int op2 = ans[i-1][j];
//                 ans[i][j] = op1 + op2;
//                 // ans[i][j] = ans[i-1][j-a[i-1]] or ans[i-1][j];
//             }
//             else
//             {
//                 ans[i][j] = ans[i-1][j];
//             }
//         }
//     }
//     for(int i=0;i<=n;i++)
//     {
//         for(int j=0;j<=s;j++)
//         {
//             if(ans[i][j]) cout<<ans[i][j]<<" ";
//             else cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     // 
//     // if(ans[n][s]) cout<<"YES"<<endl;
//     // else cout<<"NO"<<endl;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int memoization[1005][1005];

bool subset_sum(int n,int s,int a[])
{
    if(memoization[n][s]!=-1) return memoization[n][s];
    if(n==0)
    {
        if(s==0) 
        { 
            return 1;
        }
        else return 0;
    }
    if(a[n-1]<=s)
    {
        int op1 = subset_sum(n-1,s-a[n-1],a);
        int  op2 = subset_sum(n-1,s,a);
        memoization[n][s] = op1 + op2;
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
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            memoization[i][j]=-1;
        }
    }

    subset_sum(n,s,a);

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            if(memoization[i][j]) cout<<memoization[i][j]<<" ";
            else cout<<memoization[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}