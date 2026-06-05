#include <bits/stdc++.h>
using namespace std;

class SearchMatrix
{
public:
    bool search_brute(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == target)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool search_better(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();

        for (int i = 0; i < m; i++)
        {
            if (target >= matrix[i][0] && target <= matrix[i].back())
            {
                int low = 0, high = matrix[i].size() - 1;
                while (low <= high)
                {
                    int mid = low + (high - low) / 2;
                    if (matrix[i][mid] == target)
                        return true;
                    else if (matrix[i][mid] < target)
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
            }
        }
        return false;
    }

    // Optimized approach
    bool search_optimized(vector<vector<int>> &matrix, int target){
        if(matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = (n * m) - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int row = mid / n;
            int col = mid % n;

            if(matrix[row][col] == target) 
                return true;
            else if(matrix[row][col] < target) 
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return false;
    }
};

int main()
{
    SearchMatrix sol;

    vector<vector<int>> matrix1 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    vector<vector<int>> matrix2 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target1 = 3;
    int target2 = 300;
    bool ans1 = sol.search_brute(matrix1, target1);
    cout << "Answer using brute : " << ans1;

    cout << endl;

    bool ans2 = sol.search_better(matrix2, target2);
    cout << "Answer using better : " << ans2;

    cout << endl;

    bool ans3 = sol.search_optimized(matrix1, target1);
    cout << "Answer using optimized : " << ans3;
 
    return 0;
}