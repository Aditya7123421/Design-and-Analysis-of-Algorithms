/*
Algorithm: Travelling Salesman Problem (Bitmask DP / Held-Karp)
Paradigm: Dynamic Programming
Time Complexity: O(n^2 * 2^n)
Space Complexity: O(n * 2^n)

Description:
Computes minimum Hamiltonian cycle cost
starting and ending at city 0.
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int n = 4;

    // Distance matrix
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int totalMasks = 1 << n;

    // dp[mask][city] = minimum cost to reach 'city'
    // after visiting cities in 'mask'
    vector<vector<int>> dp(
        totalMasks,
        vector<int>(n, INT_MAX)
    );

    // Base case: start from city 0
    dp[1][0] = 0;

    // Build DP table
    for(int mask = 1; mask < totalMasks; mask++)
    {
        for(int currentCity = 0; currentCity < n; currentCity++)
        {
            // Check if currentCity is included in mask
            if(mask & (1 << currentCity))
            {
                if(dp[mask][currentCity] == INT_MAX)
                    continue;

                // Try visiting next unvisited city
                for(int nextCity = 0; nextCity < n; nextCity++)
                {
                    if(!(mask & (1 << nextCity)))
                    {
                        int newMask =
                            mask | (1 << nextCity);

                        dp[newMask][nextCity] = min(
                            dp[newMask][nextCity],
                            dp[mask][currentCity] +
                            dist[currentCity][nextCity]
                        );
                    }
                }
            }
        }
    }

    int finalMask = totalMasks - 1;
    int minimumCost = INT_MAX;

    // Add cost to return to starting city (0)
    for(int city = 1; city < n; city++)
    {
        minimumCost = min(
            minimumCost,
            dp[finalMask][city] +
            dist[city][0]
        );
    }

    cout << "Minimum TSP Cost: "
         << minimumCost << endl;

    return 0;
}
