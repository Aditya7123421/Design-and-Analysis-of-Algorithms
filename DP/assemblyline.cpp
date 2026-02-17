/*
Algorithm: Assembly Line Scheduling
Paradigm: Dynamic Programming
Time Complexity: O(n)
Space Complexity: O(n)

Description:
Computes the minimum time required to process a product
through two assembly lines with five stations each.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    const int n = 5;

    // Processing times at stations
    int a1[n] = {7, 9, 3, 4, 8};
    int a2[n] = {8, 5, 6, 4, 5};

    // Transfer times between lines
    int t1[n-1] = {2, 3, 1, 3};
    int t2[n-1] = {2, 1, 2, 2};

    // Entry and exit times
    int e1 = 2, e2 = 4;
    int x1 = 3, x2 = 2;

    // DP arrays
    int f1[n], f2[n];

    // Base case (first station)
    f1[0] = e1 + a1[0];
    f2[0] = e2 + a2[0];

    // Fill DP arrays
    for(int i = 1; i < n; i++) {

        f1[i] = min(
            f1[i-1] + a1[i],
            f2[i-1] + t2[i-1] + a1[i]
        );

        f2[i] = min(
            f2[i-1] + a2[i],
            f1[i-1] + t1[i-1] + a2[i]
        );
    }

    // Add exit times
    int finalTime = min(
        f1[n-1] + x1,
        f2[n-1] + x2
    );

    cout << "Minimum time required: "
         << finalTime << endl;

    return 0;
}
