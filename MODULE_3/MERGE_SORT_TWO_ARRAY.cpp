#include<bits/stdc++.h>
using namespace std;
void mergesort(int arr1[],int arr2[],int size1,int size2,int mergearr[])
{
    int arr1ptr=0; //index for arr1;
    int arr2ptr=0; //index for arr2;
    int mergeptr=0; //index for mergearr;

    while(arr1ptr < size1 && arr2ptr < size2)
    {
        if(arr1[arr1ptr]<=arr1[arr2ptr])
        {
            mergearr[mergeptr]=arr1[arr1ptr];
            arr1ptr++;
        }
        else
        {
            mergearr[mergeptr]=arr2[arr2ptr];
            arr2ptr++;
        }
        mergeptr++;
    }
    while(arr1ptr < size1)
    {
        mergearr[mergeptr]=arr1[arr1ptr];
        arr1ptr++;
        mergeptr++;
    }
    while(arr2ptr < size2)
    {
        mergearr[mergeptr]=arr2[arr2ptr];
        arr2ptr++;
        mergeptr++;
    }
}
int main()
{
    int size1; //size 1st array
    cin>>size1;
    int arr1[size1];
    for(int i=0;i<size1;i++)
    {
        cin>>arr1[i];
    }

    int size2; //size 2nd array;
    cin>>size2;
    int arr2[size2];
    for(int i=0;i<size2;i++)
    {
        cin>>arr2[i];
    }

    int mergearrsize=size1+size2; //size merge array;
    int mergearr[mergearrsize];


    // cout<<"Original array:";
    // for(int i=0;i<size1;i++)
    // {
    //     cout<<arr1[i]<<" ";
    // }
    // // cout<<endl;
    // for(int i=0;i<size2;i++)
    // {
    //     cout<<arr2[i]<<" ";
    // }

    // cout<<endl;

    mergesort(arr1,arr2,size1,size2,mergearr);

    // cout<<"Sorted array:";
    for(int i=0;i<mergearrsize;i++)
    {
        cout<<mergearr[i]<<" ";
    }
    return 0;
}