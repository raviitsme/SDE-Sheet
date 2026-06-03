#include<bits/stdc++.h>
using namespace std;

class MergeIntervals{
public:
    // Brute Force solution
    vector<vector<int>> merge_intervals_brute(vector<vector<int>> &intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(!ans.empty() && end <= ans.back()[1]) {
                continue;
            }
            for(int j = i + 1; j < n; j++) {
                if(intervals[j][0] <= end) {
                    end = max(intervals[j][1], end);
                } else {
                    break;
                }
            }
            ans.push_back({start, end});
        }
        return ans;
    }

    // Optimized solution
    vector<vector<int>> merge_intervals_optimal(vector<vector<int>> &intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            if(ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }

    void printArr(vector<vector<int>> &arr) {
        for(auto i : arr) {
            cout << "[" << i[0] << ", " << i[1] << "] ";
        }
        cout << endl;
    }
};

int main() {
    MergeIntervals mi;
    vector<vector<int>> intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> intervals2 = {{1, 8}, {2, 5}, {6, 7}};

    cout << "Original: ";
    mi.printArr(intervals1);
    
    vector<vector<int>> res_brute1 = mi.merge_intervals_brute(intervals1);
    cout << "Brute Force Result: ";
    mi.printArr(res_brute1);

    vector<vector<int>> res_optimal1 = mi.merge_intervals_optimal(intervals1);
    cout << "Optimal Result    : ";
    mi.printArr(res_optimal1);
    cout << "\n";

    cout << "Original: ";
    mi.printArr(intervals2);
    
    vector<vector<int>> res_brute2 = mi.merge_intervals_brute(intervals2);
    cout << "Brute Force Result: ";
    mi.printArr(res_brute2);

    vector<vector<int>> res_optimal2 = mi.merge_intervals_optimal(intervals2);
    cout << "Optimal Result    : ";
    mi.printArr(res_optimal2);

    return 0;
}
