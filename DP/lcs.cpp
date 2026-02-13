/*
Algorithm: Longest Common Subsequence (LCS)
Paradigm: Dynamic Programming
Time Complexity: O(m * n)
Space Complexity: O(m * n)

Description:
Computes the length and actual longest common subsequence
between two given strings using bottom-up dynamic programming.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    string s1 = "abafafafdvzxx";
    string s2 = "bafdn";

    int m = s1.length();
    int n = s2.length();

    // Create DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Print DP table (for understanding)
    cout << "DP Table:\n";
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    // Backtrack to find LCS
    string lcs = "";
    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs += s1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    cout << "\nLength of LCS: " << dp[m][n] << endl;
    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}
