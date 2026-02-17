/*
Algorithm: Maximum Subarray (Divide and Conquer)
Paradigm: Divide and Conquer
Time Complexity: O(n log n)
Space Complexity: O(log n)

Description:
Finds the maximum sum of a contiguous subarray
using divide and conquer approach.
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int crossSum(vector<int>& arr,
             int start, int mid, int end) {

    int sum = 0;
    int leftSum = INT_MIN;

    // Maximum suffix sum (left side)
    for(int i = mid; i >= start; i--) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;
    int rightSum = INT_MIN;

    // Maximum prefix sum (right side)
    for(int i = mid + 1; i <= end; i++) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubarray(vector<int>& arr,
                int start, int end) {

    if(start == end)
        return arr[start];

    int mid = (start + end) / 2;

    int leftMax  = maxSubarray(arr, start, mid);
    int rightMax = maxSubarray(arr, mid + 1, end);
    int crossMax = crossSum(arr, start, mid, end);

    return max({leftMax, rightMax, crossMax});
}

int main() {

    vector<int> arr = {
        -2, 1, -3, 4, -1,
         2, 1, -5, 4
    };

    int result =
        maxSubarray(arr, 0, arr.size() - 1);

    cout << "Maximum Subarray Sum: "
         << result << endl;

    return 0;
}
