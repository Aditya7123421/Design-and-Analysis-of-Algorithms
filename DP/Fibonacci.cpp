/*
Algorithm: Fibonacci Series (Top-Down Dynamic Programming)

Technique:
Recursion + Memoization (Top-Down DP)

Time Complexity: O(n)
Space Complexity: O(n)

Description:
Computes the n-th Fibonacci number using
recursive calls while storing previously
computed results to avoid recomputation.

Indexing starts from 1:
F(1) = 1
F(2) = 1
*/

#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n, vector<int>& dp)
{
    // Base cases
    if(n == 1 || n == 2)
        return 1;

    // Already computed
    if(dp[n] != -1)
        return dp[n];

    // Recursive relation with memoization
    dp[n] =
        fibonacci(n - 1, dp) +
        fibonacci(n - 2, dp);

    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    // Edge case protection
    if(n <= 0) {
        cout << "Invalid Input";
        return 0;
    }

    // Memoization table
    vector<int> dp(n + 1, -1);

    cout << fibonacci(n, dp);

    return 0;
}
