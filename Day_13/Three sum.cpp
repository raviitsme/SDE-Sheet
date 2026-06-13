#include <bits/stdc++.h>
using namespace std;

class ThreeSum {
public:

    // Brute Force
    // Time Complexity : O(N^3)
    // Space Complexity : O(No. of unique triplets)

    vector<vector<int>> threeSum_brute(vector<int>& nums) {

        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                for (int k = j + 1; k < n; k++) {

                    if (nums[i] + nums[j] + nums[k] == 0) {

                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());

                        st.insert(temp);
                    }
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }

    // Better Approach
    // Time Complexity : O(N^2)
    // Space Complexity : O(N) + O(No. of unique triplets)

    vector<vector<int>> threeSum_better(vector<int>& nums) {

        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {

            unordered_set<int> hashSet;

            for (int j = i + 1; j < n; j++) {

                int third = -(nums[i] + nums[j]);

                if (hashSet.find(third) != hashSet.end()) {

                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());

                    st.insert(temp);
                }

                hashSet.insert(nums[j]);
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }

    // Optimal Approach
    // Time Complexity : O(N^2)
    // Space Complexity : O(1)

    vector<vector<int>> threeSum_optimal(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {

                long long sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {

                    ans.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j - 1])
                        j++;

                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }

        return ans;
    }
};

void printAnswer(vector<vector<int>>& ans) {

    for (auto& triplet : ans) {

        cout << "[ ";

        for (int x : triplet) {
            cout << x << " ";
        }

        cout << "]" << endl;
    }
}

int main() {

    ThreeSum solver;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    cout << "--- Brute Force ---" << endl;
    vector<vector<int>> ans1 = solver.threeSum_brute(nums);
    printAnswer(ans1);

    cout << endl;

    cout << "--- Better Approach ---" << endl;
    vector<vector<int>> ans2 = solver.threeSum_better(nums);
    printAnswer(ans2);

    cout << endl;

    cout << "--- Optimal Approach ---" << endl;
    vector<vector<int>> ans3 = solver.threeSum_optimal(nums);
    printAnswer(ans3);

    return 0;
}