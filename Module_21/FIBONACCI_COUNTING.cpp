#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if(n==0 or n==1) return 1;
    // int ans1 = fibonacci(n-1);
    // int ans2 = fibonacci(n-2);
    // return ans1+ans2;

    return fibonacci(n-1)+fibonacci(n-2);
}

// complexity o(2^n);

int main()
{
    int n;
    cin>>n;
    cout<<fibonacci(n)<<endl;
}