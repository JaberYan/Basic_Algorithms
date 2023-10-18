#include<bits/stdc++.h>
using namespace std;

int knapsack(int n,int s,int value[],int weight[])
{
    //base case 
    if(n==0 or s==0) return 0;
    if(weight[n-1]<=s)
    {
        int choice1 = knapsack(n-1,s-weight[n-1],value,weight) + value[n-1];
        int choice2 = knapsack(n-1,s,value,weight);
        return max(choice1,choice2);
    }
    else
    {
        return knapsack(n-1,s,value,weight);
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

    cout<<knapsack(n,s,value,weight)<<endl;
    return 0;
}