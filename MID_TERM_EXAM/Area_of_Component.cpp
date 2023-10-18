#include<bits/stdc++.h>
using namespace std;
const int N=1005;
char matrix[N][N];
bool visited[N][N];
int n,m;

bool isValid(int i,int j) 
{
    return (i>=0 && i<n && j>=0 && j<m);
}

int dfs(int i,int j) 
{
    if (!isValid(i,j) || visited[i][j] || matrix[i][j]=='-') return 0;
    
    visited[i][j]=true;
    
    int area=1;
    area+=dfs(i,j-1);
    area+=dfs(i,j+1);
    area+=dfs(i-1,j);
    area+=dfs(i+1,j);
    
    return area;
}

int main() 
{
    cin>>n>>m;
    for (int i=0;i<n;i++) 
    {
        for (int j=0;j<m;j++) 
        {
            cin>>matrix[i][j];
        }
    }
    
    int minArea=INT_MAX;
    
    for (int i=0;i<n;i++) 
    {
        for (int j=0;j<m;j++) 
        {
            if (!visited[i][j] && matrix[i][j] =='.')
            {
                int area = dfs(i,j);
                minArea = min(minArea, area);
            }
        }
    }

    if (minArea==INT_MAX) 
    {
        cout<<-1;
    } 
    else 
    {
        cout<<minArea;
    }
    return 0;
}
