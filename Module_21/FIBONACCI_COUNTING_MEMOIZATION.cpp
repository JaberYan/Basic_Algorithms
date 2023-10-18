#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N = 1e5+9;

ll memoization[N];

ll fibonacci(ll n)
{
    if(memoization[n]!=-1) return memoization[n];
    if(n==0 or n==1) return 1;
    // int ans = fibonacci(n-1);
    // int ans1 = fibonacci(n-2);
    // return memoization[n] = ans+ans1;
    return memoization[n] = fibonacci(n-1) + fibonacci(n-2);
}
         
int main()
{
    ll n;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        memoization[i]=-1;
    }
    cout<<fibonacci(n)<<endl;
    return 0;
}