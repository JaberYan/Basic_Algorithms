// #include<bits/stdc++.h>
// using namespace std; 
// const int MAX = 100005;

// int memoization[MAX];
// int n;
// bool reach_value(int current)
// {
//     if(current == 1) return true;
//     if(current<1) return false;
//     if(memoization[current]!=-1) return memoization[current];
//     if(current%2==0)
//     {
//           bool op1= reach_value(current-3);
//           bool op2= reach_value(current/2);
//           return memoization[current] = op1|| op2;
//     }
//     else
//     {
//           return memoization[current] = reach_value(current-3);
//     }
// }
//  int main(){
   
//    int t;
//    cin>>t;
//    while(t--)
//    {
//         memset(memoization,-1,sizeof(memoization));
//         cin>>n;
//         if(reach_value(n))
//         {
//         cout<<"YES"<<endl;
//         }
//         else
//         {
//             cout<<"NO"<<endl;
//         }
//    }
//   return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// ll inf=1e5+7;
// int main()
// {
//     ll test;
//     cin>>test;
//     for(int i=0;i<test;i++)
//     {
//         ll n;
//         cin>>n;
//         bool dp[inf];
//          for(int i=0;i<inf;i++)
//          {
//              dp[i]=false;
//          }
//         dp[1]=true;
//         for(ll i=1;i<=n;i++)
//         {
//             if(dp[i])
//             {
//                 if(i*2<=n)
//                 {
//                   dp[i*2]=true;
//                 }    
//                 if(i+3<=n)
//                 {
//                   dp[i+3] = true;
//                 }     
//             }
//         }
//         if(dp[n])
//         {
//             cout<<"YES"<<endl;
//         }
//         else
//         {
//             cout<<"NO"<<endl;
//         }
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int main()
{
  int p,d1,d2;
  cin>>p>>d1>>d2;
  int sum=(d1*p);
  int sum2=sum/d2;
  cout<<sum2-p<<endl;
    return 0;
}