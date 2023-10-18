#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;

int memoization[N][N];

int knapsack(int n,int s,int value[],int weight[])
{
    //base case 
    if(n==0 or s==0) return 0;
    if(memoization[n][s]!=-1) return memoization[n-1][s];
    if(weight[n-1]<=s)
    {
        int choice1 = knapsack(n-1,s-weight[n-1],value,weight) + value[n-1];
        int choice2 = knapsack(n-1,s,value,weight);
        memoization[n][s] = max(choice1,choice2);
        return memoization[n][s];
    }
    else
    {
        memoization[n][s] = knapsack(n-1,s,value,weight);
        return memoization[n][s];
    }
}

int main()
{
    int n;
    cin>>n;
    int value[n],weight[n];
    for(int i=0;i<n;i++)
    {
        cin>>value[i];
    }

    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
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

    cout<<knapsack(n,s,value,weight)<<endl;
    return 0;
}