#include <bits/stdc++.h>
using namespace std;

const int dx[]={-2,-1,1,2,2,1,-1,-2};
const int dy[]={1,2,2,1,-1,-2,-2,-1};

bool isValid(int x,int y,int n,int m) 
{
    return x>=0 && x<n && y>=0 && y<m;
}

int bfs(int n,int m,pair<int, int> start,pair<int, int> end) 
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> distance(n, vector<int>(m, 0));

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        if (current == end) {
            return distance[current.first][current.second];
        }

        for (int i = 0; i < 8; ++i) {
            int newX = current.first + dx[i];
            int newY = current.second + dy[i];

            if (isValid(newX, newY, n, m) && !visited[newX][newY]) {
                visited[newX][newY] = true;
                distance[newX][newY] = distance[current.first][current.second] + 1;
                q.push({newX, newY});
            }
        }
    }

    return -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        pair<int, int> knight, queen;
        cin >> knight.first >> knight.second >> queen.first >> queen.second;

        int result = bfs(n, m, knight, queen);
        cout << result << endl;
    }

    return 0;
}