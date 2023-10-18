#include<bits/stdc++.h>
using namespace std;

bool subset_sum(int n,int s,int a[])
{
    if(n==0) return s==0;
    if(a[n-1]<=s)
    {
        bool op1 = subset_sum(n-1,s-a[n-1],a);
        bool op2 = subset_sum(n-1,s,a);
        return op1 or op2;
    }
    else
    {
        return subset_sum(n-1,s,a);
    }
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
    if(subset_sum(n,s,a))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}