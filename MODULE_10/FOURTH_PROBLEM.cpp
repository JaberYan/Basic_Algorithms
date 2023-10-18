#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

struct State {
    int i, j, level;
    State(int _i, int _j, int _level) : i(_i), j(_j), level(_level) {}
};

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const char dirChar[] = {'L', 'R', 'U', 'D'};
enum Direction { LEFT, RIGHT, UP, DOWN };

vector<pii> direc = {{0,-1},{0,1},{-1,0},{1,0}};

int n, m;
vector<string> g;

bool isValid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> level(n, vector<int>(m, -1));
    vector<vector<pii>> parent(n, vector<pii>(m, {-1, -1}));

    queue<State> q;
    q.push(State(si, sj, 0));
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty()) {
        State s = q.front();
        q.pop();

        int i = s.i;
        int j = s.j;

        for (int d = 0; d < 4; ++d) {
            int ni = i + dx[d];
            int nj = j + dy[d];

            if (isValid(ni, nj) && !visited[ni][nj] && g[ni][nj] != '#') {
                q.push(State(ni, nj, s.level + 1));
                visited[ni][nj] = true;
                level[ni][nj] = s.level + 1;
                parent[ni][nj] = {i, j};
            }
        }
    }
}

int main() {
    int si, sj, di, dj;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        for (int j = 0; j < m; j++) {
            if (x[j] == 'A')
                si = i, sj = j;
            if (x[j] == 'B')
                di = i, dj = j;
        }
        g.push_back(x);
    }

    bfs(si, sj);
    if (level[di][dj] != -1) {
        cout << "YES" << endl;
        cout << level[di][dj] << endl;

        vector<pii> path;
        pii curr = {di, dj};

        while (!(curr.first == si && curr.second == sj)) {
            path.push_back(curr);
            curr = parent[curr.first][curr.second];
        }
        path.push_back({si, sj});
        reverse(path.begin(), path.end());

        for (int i = 1; i < path.size(); i++) {
            pii prev = path[i - 1];
            pii curr = path[i];
            Direction dir;

            for (int d = 0; d < 4; ++d) {
                if (prev.first + dx[d] == curr.first && prev.second + dy[d] == curr.second) {
                    dir = static_cast<Direction>(d);
                    break;
                }
            }

            cout << dirChar[dir];
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
