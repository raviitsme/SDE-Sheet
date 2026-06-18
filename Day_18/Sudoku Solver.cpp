#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    vector<vector<int>> rowUsed;
    vector<vector<int>> colUsed;
    vector<vector<int>> boxUsed;

    bool solve(vector<vector<char>>& board) {

        for(int row = 0; row < 9; row++) {

            for(int col = 0; col < 9; col++) {

                if(board[row][col] == '.') {

                    for(char ch = '1'; ch <= '9'; ch++) {

                        int num = ch - '0';
                        int box = (row / 3) * 3 + (col / 3);

                        if(!rowUsed[row][num] &&
                           !colUsed[col][num] &&
                           !boxUsed[box][num]) {

                            board[row][col] = ch;

                            rowUsed[row][num] = 1;
                            colUsed[col][num] = 1;
                            boxUsed[box][num] = 1;

                            if(solve(board))
                                return true;

                            board[row][col] = '.';

                            rowUsed[row][num] = 0;
                            colUsed[col][num] = 0;
                            boxUsed[box][num] = 0;
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

public:

    void solveSudoku(vector<vector<char>>& board) {

        rowUsed.assign(9, vector<int>(10, 0));
        colUsed.assign(9, vector<int>(10, 0));
        boxUsed.assign(9, vector<int>(10, 0));

        for(int row = 0; row < 9; row++) {

            for(int col = 0; col < 9; col++) {

                if(board[row][col] != '.') {

                    int num = board[row][col] - '0';
                    int box = (row / 3) * 3 + (col / 3);

                    rowUsed[row][num] = 1;
                    colUsed[col][num] = 1;
                    boxUsed[box][num] = 1;
                }
            }
        }

        solve(board);
    }
};

int main() {

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution obj;
    obj.solveSudoku(board);

    for(auto &row : board) {
        for(auto &cell : row)
            cout << cell << " ";
        cout << endl;
    }

    return 0;
}