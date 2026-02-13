/*
Algorithm: 0/1 Knapsack
Paradigm: Dynamic Programming
Time Complexity: O(n * W)
Space Complexity: O(n * W)

Description:
Computes the maximum achievable value within given capacity.
Also reconstructs the items selected using backtracking.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n = 4;
    int W = 7;

    int weights[] = {1, 3, 4, 5};
    int values[]  = {1, 4, 5, 7};

    // DP table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill DP table
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= W; j++) {

            if(weights[i - 1] <= j) {
                dp[i][j] = max(
                    dp[i - 1][j],
                    dp[i - 1][j - weights[i - 1]] + values[i - 1]
                );
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Print DP table (for learning)
    cout << "DP Table:\n";
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= W; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMaximum Value: " << dp[n][W] << endl;

    // Backtracking to find selected items
    cout << "Items selected (0-based index): ";

    int i = n;
    int j = W;

    vector<int> selectedItems;

    while(i > 0 && j > 0) {

        if(dp[i][j] == dp[i - 1][j]) {
            i--;
        }
        else {
            selectedItems.push_back(i - 1);
            j -= weights[i - 1];
            i--;
        }
    }

    reverse(selectedItems.begin(), selectedItems.end());

    for(int index : selectedItems) {
        cout << index << " ";
    }

    return 0;
}
