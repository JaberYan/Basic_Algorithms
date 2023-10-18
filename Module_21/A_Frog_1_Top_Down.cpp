#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int memoization[N];

int choice(int n,int a[])
{
    if(memoization[n]!=-1) return memoization[n];
    if(n==1) return 0;
    else if(n>=3)
    {
        int choice1 = choice(n-1,a)+abs(a[n]-a[n-1]);
        int choice2 = choice(n-2,a)+abs(a[n]-a[n-2]);
        memoization[n] = min(choice1,choice2);
        return min(choice1,choice2);
    }
    else
    {
        memoization[n] = abs(a[2]-a[1]);
        return abs(a[2]-a[1]);
    }
}


int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<=n;i++)
    {
        memoization[i]=-1;
    }
    cout<<choice(n,a)<<endl;
    return 0;
}