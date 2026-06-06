#include<bits/stdc++.h>
using namespace std;

class UniqueGridPaths{
private:

    // Brute helper
    int countPaths(int i, int j, int m, int n) {
        if(i == m - 1 && j == n - 1) return 1;

        if(i >= m || j >= n) return 0;

        int down = countPaths(i + 1, j, m, n);
        int right = countPaths(i, j + 1, m, n);

        return down + right;
    }

    // Better Helper
    int countPathsMemo(int i, int j, int m, int n, vector<vector<int>> &dp) {
        if(i == m - 1 && j == n - 1) return 1;

        if(i >= m || j>= n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int down = countPathsMemo(i + 1, j, m, n, dp);
        int right = countPathsMemo(i, j + 1, m, n, dp);

        return dp[i][j] = down + right;
    }
public:

    // Brute force
    int unique_paths_brute(int m, int n){
        return countPaths(0,0,m,n);
    }

    // Memoization
    int unique_paths_better(int m, int n){
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countPathsMemo(0, 0, m, n, dp);
    }

    int unique_paths_optimal(int m, int n){
        int N = m + n - 2;

        int r = min(m - 1, n - 1);

        long long ans = 1;

        for(int i = 1; i <=r; i++) {
            ans = ans * (N - r + i);
            ans = ans / i;
        }

        return (int)ans;
    }
};

int main() {
    UniqueGridPaths uniquePaths;

    int m = 3, n = 2;
    int ans_brute = uniquePaths.unique_paths_brute(m,n);
    cout << "Answer using brute : " << ans_brute << endl;
    cout << "\n";

    int ans_better = uniquePaths.unique_paths_better(m, n);
    cout << "Answer using better : " << ans_better << endl;
    cout << "\n";   

    int ans_optimized = uniquePaths.unique_paths_optimal(m, n);
    cout << "Answer using optimized : " << ans_optimized << endl;
    cout << "\n"; 
}