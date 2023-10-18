#include<bits/stdc++.h>
using namespace std;

int lcs(string a,int n,string b,int m)
{
    if(n==0 || m==0) return 0;
    if(a[n-1] == b[m-1])
    {
        return lcs(a,n-1,b,m-1)+1;
    }
    else
    {
        return max(lcs(a,n-1,b,m),lcs(a,n,b,m-1));
    }
}
int main()
{
    string a,b;
    cin>>a>>b;
    cout<<lcs(a,a.size(),b,b.size())<<endl;
    return 0;
}