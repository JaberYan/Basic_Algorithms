#include<bits/stdc++.h>
using namespace std;

bool solve(int n,int a[],int x,int sum)
{
    if(n==0)
    {
        if(sum==x)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool plus = solve(n-1,a,x,sum+a[n-1]);
    bool minas = solve(n-1,a,x,sum-a[n-1]);
    return plus || minas;
}
int main()
{
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    if(solve(n,a,x,0))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}