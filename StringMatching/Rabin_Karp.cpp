/*
Algorithm: Rabin-Karp String Matching
Time Complexity:
    Average Case: O(n + m)
    Worst Case:   O(n * m)

Description:
Finds all occurrences of a pattern in a text
using rolling hash technique.
*/

#include <iostream>
using namespace std;

int main() {

    string text = "GEEKSFORGEEKS";
    string pattern = "GEE";

    int textLength = text.length();
    int patternLength = pattern.length();

    const int alphabetSize = 256;
    const int primeMod = 101;

    int highestPower = 1;
    int patternHash = 0;
    int windowHash = 0;

    // Compute highestPower = d^(m-1) % primeMod
    for(int i = 0; i < patternLength - 1; i++)
        highestPower =
            (highestPower * alphabetSize) % primeMod;

    // Compute initial hash values
    for(int i = 0; i < patternLength; i++) {
        patternHash =
            (alphabetSize * patternHash + pattern[i]) % primeMod;

        windowHash =
            (alphabetSize * windowHash + text[i]) % primeMod;
    }

    cout << "Pattern found at indices: ";

    for(int i = 0; i <= textLength - patternLength; i++) {

        if(patternHash == windowHash) {

            bool match = true;

            for(int j = 0; j < patternLength; j++) {
                if(pattern[j] != text[i + j]) {
                    match = false;
                    break;
                }
            }

            if(match)
                cout << i << " ";
        }

        // Compute hash for next window
        if(i < textLength - patternLength) {

            windowHash =
                (alphabetSize *
                (windowHash - text[i] * highestPower)
                + text[i + patternLength]) % primeMod;

            if(windowHash < 0)
                windowHash += primeMod;
        }
    }

    cout << endl;

    return 0;
}
