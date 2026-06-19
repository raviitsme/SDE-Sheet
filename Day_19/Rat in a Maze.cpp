#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, vector<vector<int>> &mat, int n,
           vector<vector<int>> &visited,
           string path, vector<string> &ans) {

    if (i == n - 1 && j == n - 1) {
        ans.push_back(path);
        return;
    }

    visited[i][j] = 1;

    // DOWN
    if (i + 1 < n && mat[i + 1][j] == 1 && !visited[i + 1][j]) {
        solve(i + 1, j, mat, n, visited, path + "D", ans);
    }

    // LEFT
    if (j - 1 >= 0 && mat[i][j - 1] == 1 && !visited[i][j - 1]) {
        solve(i, j - 1, mat, n, visited, path + "L", ans);
    }

    // RIGHT
    if (j + 1 < n && mat[i][j + 1] == 1 && !visited[i][j + 1]) {
        solve(i, j + 1, mat, n, visited, path + "R", ans);
    }

    // UP
    if (i - 1 >= 0 && mat[i - 1][j] == 1 && !visited[i - 1][j]) {
        solve(i - 1, j, mat, n, visited, path + "U", ans);
    }

    visited[i][j] = 0; // backtracking
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<string> ans;

    if (arr[0][0] == 0) return ans;

    solve(0, 0, arr, n, visited, "", ans);

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<string> result = searchMaze(mat, n);

    if (result.empty()) {
        cout << "No path" << endl;
    } else {
        for (auto &s : result) {
            cout << s << endl;
        }
    }

    return 0;
}