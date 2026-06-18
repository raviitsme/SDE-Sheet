#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    void solve(int row,
               vector<string>& board,
               vector<vector<string>>& ans,
               vector<int>& leftRow,
               vector<int>& upperDiagonal,
               vector<int>& lowerDiagonal,
               int n) {

        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++) {

            if(leftRow[col] == 0 &&
               lowerDiagonal[row + col] == 0 &&
               upperDiagonal[n - 1 + col - row] == 0) {

                board[row][col] = 'Q';

                leftRow[col] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                solve(row + 1, board, ans,
                      leftRow, upperDiagonal,
                      lowerDiagonal, n);

                board[row][col] = '.';

                leftRow[col] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

public:

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        vector<int> leftRow(n, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);

        solve(0, board, ans,
              leftRow, upperDiagonal,
              lowerDiagonal, n);

        return ans;
    }
};

int main() {

    int n = 4;

    Solution obj;

    vector<vector<string>> ans = obj.solveNQueens(n);

    for(auto &board : ans) {

        cout << "Solution:\n";

        for(auto &row : board)
            cout << row << endl;

        cout << endl;
    }

    return 0;
}