/*
Algorithm: Karatsuba Multiplication
Paradigm: Divide and Conquer
Time Complexity: O(n^1.585)
Space Complexity: O(log n)

Description:
Multiplies two 7-digit numbers using Karatsuba algorithm.
*/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long karatsuba(long long x, long long y) {

    if(x < 10 || y < 10)
        return x * y;

    int len = max(
        (int)log10(x) + 1,
        (int)log10(y) + 1
    );

    int m = len / 2;

    long long ten = 1;
    for(int i = 0; i < m; i++)
        ten *= 10;

    long long a = x / ten;
    long long b = x % ten;
    long long c = y / ten;
    long long d = y % ten;

    long long x2 = karatsuba(a, c);      // ac
    long long x0 = karatsuba(b, d);      // bd
    long long x1 = karatsuba(a + b, c + d) - x2 - x0;

    return x2 * ten * ten + x1 * ten + x0;
}

int main() {

    long long num1 = 1234567;
    long long num2 = 7654321;

    cout << "Result: "
         << karatsuba(num1, num2) << endl;

    return 0;
}
