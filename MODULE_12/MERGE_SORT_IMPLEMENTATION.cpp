#include<bits/stdc++.h>
using namespace std;
void merge_sort(int a[],int l,int m,int r)
{
    int leftSize = m-l+1;
    int L[leftSize];
    int k=0;
    for(int i=l;i<=m;i++)
    {
        L[k]=a[i];
        k++;
    }
    int rightSize=r-m;
    int R[rightSize];
    k=0;
    for(int i=m+1;i<=r;i++)
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
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    merge_sort(a,0,3,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}