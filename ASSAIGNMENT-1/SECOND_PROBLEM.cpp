#include<bits/stdc++.h>
using namespace std;
int main() 
{
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i < n;i++) 
    {
        cin>>arr[i];
    }
    int x;
    cin>>x;

    int left=0;
    int right=sizeof(arr)/sizeof(arr[0]);

    while (left<=right)
    {
        int mid=left+(right-left)/2;
        if (arr[mid]==x)
        {
            cout<<mid<<endl;
            return 0;
        }
        else if(x<arr[mid])
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }

    cout<<"Not Found"<<endl;
    return 0;}
