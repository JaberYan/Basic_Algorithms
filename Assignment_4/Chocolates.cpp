#include <iostream>
#include <vector>
using namespace std;

bool canDivideEqually(vector<int>& chocolates) {
    int totalChocolates = 0;
    for (int c : chocolates) {
        totalChocolates += c;
    }

    if (totalChocolates % 2 != 0) {
        return false; // If the total number of chocolates is odd, it cannot be divided equally.
    }

    int targetSum = totalChocolates / 2;
    int n = chocolates.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(targetSum + 1, false));

    // Initialization
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Dynamic programming
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= targetSum; ++j) {
            if (chocolates[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - chocolates[i - 1]];
            }
        }
    }

    return dp[n][targetSum];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> chocolates(n);
        for (int i = 0; i < n; ++i) {
            cin >> chocolates[i];
        }

        if (canDivideEqually(chocolates)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
