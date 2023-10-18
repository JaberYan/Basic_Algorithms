// #include <bits/stdc++.h>
// using namespace std;

// const int dx[]={-1,1,0,0};
// const int dy[]={0,0,-1,1};


// void dfs(int x,int y,vector<vector<char>>& matrix,vector<vector<bool>>& visited) 
// {
//     visited[x][y]=true;

//     for (int i=0;i<4;i++) 
//     {
//         int newX=x+dx[i];
//         int newY=y+dy[i];

//         if (newX>=0 && newX<matrix.size() && newY>=0 && newY<matrix[0].size() &&
//             matrix[newX][newY]=='.' && !visited[newX][newY]) 
//             {
//             dfs(newX,newY,matrix,visited);
//         }
//     }
// }

// int main() 
// {
//     int n,m;
//     cin>>n>>m;

//     vector<vector<char>> matrix(n,vector<char>(m));
//     for (int i=0;i<n;i++) 
//     {
//         for (int j=0;j<m;j++) 
//         {
//             cin>>matrix[i][j];
//         }
//     }

//     int si,sj,di,dj;
//     cin>>si>>sj>>di>>dj;

//     vector<vector<bool>> visited(n,vector<bool>(m,false));

//     dfs(si,sj,matrix,visited);

//     if (visited[di][dj]) 
//     {
//         cout<<"YES\n";
//     } 
//     else 
//     {
//         cout<<"NO\n";
//     }
//     return 0;
// }
#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
const int N = 1005;
bool vis[N][N];
int dis[N][N];
int n, m;
char a[N][N];
vector<pi> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


bool isValid(int cI, int cJ)
{
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m)
        return true;
    else
        return false;
}
void bfs(int si, int sj)
{
    queue<pi> q;
    q.push({si, sj});
    dis[si][sj] = 0;
    vis[si][sj] = true;
    while (!q.empty())
    {
        pi parent = q.front();
        int pI = parent.first;
        int pJ = parent.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            pi p = path[i];
            int cI = pI + p.first;
            int cJ = pJ + p.second;
            if (isValid(cI, cJ) && !vis[cI][cJ] && a[cI][cJ]=='.')
            {
                vis[cI][cJ] = true;
                q.push({cI, cJ});
                dis[cI][cJ] = dis[pI][pJ] + 1;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int si, sj,di,dj;
    cin >> si >> sj>>di>>dj;
    bfs(si, sj);
    if(vis[di][dj])
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}