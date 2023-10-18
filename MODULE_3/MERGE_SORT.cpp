#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int nums[N]; //main array;

void merge(int l,int r,int mid)
{
    int left_size=mid-l+1;
    int L[left_size+1];

    int right_size=r-mid;
    int R[right_size+1];

    for(int i=l,j=0;i<=mid;i++,j++)
    {
        L[j]=nums[i]; //left er value gula;
    }
    for(int i=mid+1,j=0;i<=r;i++,j++)
    {
        R[j]=nums[i]; //right side er value gula;
    }


    L[left_size]=INT_MIN; //infinity
    R[right_size]=INT_MIN; //infinity


    int lp=0,rp=0; //two pointer of two array;
    for(int i=l;i<=r;i++)
    {
        if(L[lp]>=R[rp])
        {
            nums[i]=L[lp];
            lp++;
        }
        else
        {
            nums[i]=R[rp];
            rp++;
        }
    }
}

void mergesort(int l,int r)
{
    if(l==r) return; //based case;
    int mid=(l+r)/2; //mid value;
    mergesort(l,mid); //merge sort left;
    mergesort(mid+1,r); //merge sort right;
    merge(l,r,mid); //tukra gula merge kortlam;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int l=0;
    int r=n-1;

    // cout<<"Original array:";
    // for(int i=0;i<n;i++)
    // {
    //     cout<<nums[i]<<" ";
    // }
    // cout<<endl;

    mergesort(0,n-1);

    // cout<<"Sorted array:";
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}