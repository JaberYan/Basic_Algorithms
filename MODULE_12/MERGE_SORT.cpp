#include<bits/stdc++.h>
using namespace std;
void merge_sort(int a[],int l,int r,int mid)
{
    int leftSize=mid-l+1;
    int L[leftSize];
    int k=0;
    for(int i=l;i<=mid;i++)
    {
        L[k]=a[i];
        k++;
    }
    int rightSize=r-mid;
    int R[rightSize];
    k=0;
    for(int i=mid+1;i<=r;i++)
    {
        R[k]=a[i];
        k++;
    }
    int i=0,j=0;
    int cur=l;
    while(i<leftSize && j<rightSize)
    {
        if(L[i]<=R[j])
        {
            a[cur]=L[i];
            i++;
        }
        else
        {
            a[cur]=R[j];
            j++;
        }
        cur++;
    }
    while(i<leftSize)
    {
        a[cur]=L[i];
        i++;
        cur++;
    }
    while(j<rightSize)
    {
        a[cur]=R[j];
        j++;
        cur++;
    }
}
void devide(int a[],int l, int r)
{
    if(l>=r) return;
    int mid=(l+r)/2;
    devide(a,l,mid);
    devide(a,mid+1,r);
    merge_sort(a,l,r,mid);
    // cout<<"This"<<endl;
    // for(int i=l;i<=mid;i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=mid+1;i<=r;i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    
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
    devide(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}