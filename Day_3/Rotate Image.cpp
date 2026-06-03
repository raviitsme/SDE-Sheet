#include<bits/stdc++.h>
using namespace std;

class RotateImage {
public:
    // Brute force
    vector<vector<int>> rotate_image_brute(vector<vector<int>> &matrix) {
        int n = matrix.size();
        vector<vector<int>> dummy(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dummy[j][n - 1 - i] = matrix[i][j];
            }
        }
        return dummy;
    }

    // Optimized approach
    void rotate_image_optimal(vector<vector<int>> &matrix) {
        int n = matrix.size();

        // Transpose first
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Then reverse
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    void printMatrix(const vector<vector<int>> &matrix) {
        for(const auto &row : matrix) {
            for(int val : row) {
                cout << val << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    RotateImage solution;

    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<int>> matrix2 = matrix1; // copying original for optimal solution
    cout << "Original matrix" << endl;
    solution.printMatrix(matrix1);
    cout << "\n";

    // Brute force
    vector<vector<int>> bruteForce = solution.rotate_image_brute(matrix1);
    cout << "Brute force : " << endl;
    solution.printMatrix(bruteForce);
    cout << endl;


    //Optimized 
    solution.rotate_image_optimal(matrix2);
    cout << "Optimized : " << endl;
    solution.printMatrix(matrix2);
    
    return 0;
}