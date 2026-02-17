/*
Algorithm: KMP String Matching
Time Complexity: O(n + m)
*/

#include <iostream>
#include <vector>
using namespace std;

void computeLps(string pattern, vector<int>& lps){

    int i = 1;
    int j = 0;

    while(i < pattern.length()){

        if(pattern[i] == pattern[j]){
            j++;
            lps[i] = j;
            i++;
        }
        else{
            if(j != 0){
                j = lps[j-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main(){

    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCAB";

    int n = text.length();
    int m = pattern.length();

    vector<int> lps(m, 0);
    computeLps(pattern, lps);

    int i = 0, j = 0;

    cout << "Pattern found at indices: ";

    while(i < n){

        if(text[i] == pattern[j]){
            i++;
            j++;
        }

        if(j == m){
            cout << i - j << " ";
            j = lps[j-1];
        }
        else if(i < n && text[i] != pattern[j]){

            if(j != 0)
                j = lps[j-1];
            else
                i++;
        }
    }

    cout << endl;

    return 0;
}
