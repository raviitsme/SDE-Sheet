#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, int currentColor, vector<vector<int>> &mat, vector<int> &colorOf) {
    int v = mat.size();

    for (int i = 0; i < v; i++) {
        if (mat[node][i] == 1 && colorOf[i] == currentColor) {
            return false;
        }
    }
    return true;
}

bool f(int node, vector<vector<int>> &mat, vector<int> &colorOf, int m) {
    int v = mat.size();

    if (node == v) return true;

    for (int currentColor = 1; currentColor <= m; currentColor++) {
        if (isSafe(node, currentColor, mat, colorOf)) {
            colorOf[node] = currentColor;

            if (f(node + 1, mat, colorOf, m)) {
                return true;
            }

            colorOf[node] = 0; // backtracking
        }
    }

    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int v = mat.size();
    vector<int> colorOf(v, 0);

    if (f(0, mat, colorOf, m))
        return "YES";

    return "NO";
}

int main() {
    int v, m;
    cin >> v >> m;

    vector<vector<int>> mat(v, vector<int>(v));

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> mat[i][j];
        }
    }

    cout << graphColoring(mat, m) << endl;

    return 0;
}