#include<bits/stdc++.h>
using namespace std;

class PascalsTriangle {
    public: 
        // Function to find an element at a given row and column [1 - based indexing]
        int nCr(int n, int r) {
            long long ans = 1;
            for(int i = 0; i < r; i++) {
                ans = ans * (n - i);
                ans = ans / (i + 1);
            }   
            return ans;
        }

        // Function to generate an entire row
        vector<int> generateRow(int row) {
            long long ans = 1;
            vector<int> ansRow;
            ansRow.push_back(1);
            for(int col = 1; col < row; col++) {
                ans = ans * (row - col);
                ans = ans / col;
                ansRow.push_back(ans);
            }
            return ansRow;
        }

        // Function to generate an entire pascal's triangle till num Rows
        vector<vector<int>> triangle(int rows) {
            long long ans = 1;
            vector<vector<int>> ansRow;
            for(int i = 1; i <= rows; i++) {
                ansRow.push_back(generateRow(i));
            }
            return ansRow;
        } 

        // Function to print an array 
        void printArray(vector<int> &arr) {
            for(auto i : arr) {
                cout << i << " ";
            }
        }
};

int main() {
    PascalsTriangle pt;
    cout << "Type 1" << endl;
    int n = 5, r = 3;
    int ele = pt.nCr(n - 1, r - 1);    
    cout << "Element at row : " << n << " and col : " << r << " is : " << ele << endl;

    cout << endl << "Type 2" << endl;

    int row = 6;
    vector<int> ans = pt.generateRow(row);
    pt.printArray(ans);  

    cout << endl << "Type 3" << endl;
    
    int totalRows = 5;
    vector<vector<int>> fullTriangle = pt.triangle(totalRows);
    
    for(int i = 0; i < fullTriangle.size(); i++) {
        pt.printArray(fullTriangle[i]);
        cout << endl;
    }

    return 0;
}