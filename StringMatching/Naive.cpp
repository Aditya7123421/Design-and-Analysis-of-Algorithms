/*
Algorithm: Naive String Matching
Time Complexity: O(n * m)

Description:
Finds all occurrences of a pattern
in a text using the naive approach.
*/

#include <iostream>
using namespace std;

int main() {

    string text = "AABAACAADAABAAAB";
    string pattern = "AABAA";

    int l1 = text.length();
    int l2 = pattern.length();

    cout << "Pattern found at indices: ";

    for(int i = 0; i <= l1 - l2; i++) {

        int j;

        for(j = 0; j < l2; j++) {

            if(text[i + j] != pattern[j])
                break;
        }

        if(j == l2)
            cout << i << " ";
    }

    cout << endl;

    return 0;
}
