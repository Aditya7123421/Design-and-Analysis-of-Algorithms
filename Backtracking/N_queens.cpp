/*
Algorithm: N-Queens
Paradigm: Backtracking
Time Complexity: O(N!)
Space Complexity: O(N^2)

Description:
Prints all possible configurations of N queens
such that no two queens attack each other.
*/

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {

    // Check same column (only rows above)
    for(int i = 0; i < row; i++) {
        if(board[i][col] == 'Q')
            return false;
    }

    // Check upper-left diagonal
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 'Q')
            return false;
    }

    // Check upper-right diagonal
    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 'Q')
            return false;
    }

    return true;
}

void solve(vector<string>& board, int row, int n, int& solutionCount) {

    if(row == n) {
        solutionCount++;
        cout << "Solution " << solutionCount << ":\n";
        for(const string& r : board)
            cout << r << endl;
        cout << endl;
        return;
    }

    for(int col = 0; col < n; col++) {

        if(isSafe(board, row, col, n)) {

            board[row][col] = 'Q';       // Place queen

            solve(board, row + 1, n, solutionCount);

            board[row][col] = '.';       // Backtrack
        }
    }
}

int main() {

    int n = 4;
    vector<string> board(n, string(n, '.'));
    int solutionCount = 0;

    solve(board, 0, n, solutionCount);

    cout << "Total Solutions: " << solutionCount << endl;

    return 0;
}
