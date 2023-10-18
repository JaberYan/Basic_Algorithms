#include<bits/stdc++.h>
using namespace std;
string find_specific_number(int arr[],int x,int n)
{
    
    int l=0,r=n-1;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(arr[mid]==x)
        {
            if(arr[mid+1]==x)
            {
                return "YES";
            }
        }
        else if(x>arr[mid])
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return "NO";
}
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
    string final_output= find_specific_number(arr,x,n);
    cout<<final_output<<endl;
    return 0;
}
