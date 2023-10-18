#include<bits/stdc++.h>
using namespace std;

const int N_MAX = 10;
const int M_MAX = 10;

int N, M;
int matrix[N_MAX][M_MAX];

int findMaxSum(int i, int j) {
    if (i == N && j == M) {
        return matrix[i][j]; // Reached the bottom-right cell
    }
    
    if (i > N || j > M) {
        return INT_MIN; // Out of bounds
    }

    // Recursively explore two possible moves (down and right)
    int moveDown = findMaxSum(i + 1, j);
    int moveRight = findMaxSum(i, j + 1);

    // Add the current cell's value to the maximum of the two moves
    return matrix[i][j] + max(moveDown, moveRight);
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> matrix[i][j];
        }
    }

    int maxSum = findMaxSum(1, 1);
    cout << maxSum << endl;

    return 0;
}
