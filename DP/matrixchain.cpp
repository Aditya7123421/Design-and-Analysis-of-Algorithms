/*
Algorithm: Matrix Chain Multiplication
Paradigm: Dynamic Programming
Time Complexity: O(n^3)
Space Complexity: O(n^2)

Description:
Computes minimum multiplication cost and
prints optimal parenthesization.
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void printParenthesis(vector<vector<int>>& split,
                      int i, int j) {

    if(i == j) {
        cout << "A" << i;
        return;
    }

    cout << "(";
    printParenthesis(split, i, split[i][j]);
    printParenthesis(split, split[i][j] + 1, j);
    cout << ")";
}

int main() {

    vector<int> arr = {10, 30, 5, 60};
    int n = arr.size() - 1;

    vector<vector<int>> dp(n+1,
                           vector<int>(n+1, 0));

    vector<vector<int>> split(n+1,
                              vector<int>(n+1, 0));

    for(int len = 2; len <= n; len++) {

        for(int i = 1; i <= n - len + 1; i++) {

            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for(int k = i; k < j; k++) {

                int cost =
                    dp[i][k] +
                    dp[k+1][j] +
                    arr[i-1] * arr[k] * arr[j];

                if(cost < dp[i][j]) {
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum Cost: "
         << dp[1][n] << endl;

    cout << "Optimal Parenthesization: ";
    printParenthesis(split, 1, n);
    cout << endl;

    return 0;
}
