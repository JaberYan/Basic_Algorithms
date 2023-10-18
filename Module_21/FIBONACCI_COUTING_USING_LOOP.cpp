#include<bits/stdc++.h>
using namespace std;
#define ll long long 


int main()
{
    ll n;
    cin>>n;
    ll loop[n+1];
    loop[0]=1;
    loop[1]=1;

    for(int i=2;i<=n;i++)
    {
        loop[i]=loop[i-1]+loop[i-2];
    }
    cout<<loop[n]<<endl;
    return 0;
}