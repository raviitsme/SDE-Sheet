#include <bits/stdc++.h>
using namespace std;

class MaxConsecutiveOnes {
public:

    // Brute Force
    // Time Complexity : O(N^3)
    // Space Complexity : O(1)

    int findMaxConsecutiveOnes_brute(vector<int>& nums) {

        int n = nums.size();
        int maxi = 0;

        for(int i = 0; i < n; i++) {

            for(int j = i; j < n; j++) {

                bool allOnes = true;

                for(int k = i; k <= j; k++) {
                    if(nums[k] == 0) {
                        allOnes = false;
                        break;
                    }
                }

                if(allOnes) {
                    maxi = max(maxi, j - i + 1);
                }
            }
        }

        return maxi;
    }

    // Optimal Approach
    // Time Complexity : O(N)
    // Space Complexity : O(1)

    int findMaxConsecutiveOnes_optimal(vector<int>& nums) {

        int cnt = 0;
        int maxi = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] == 1) {
                cnt++;
                maxi = max(maxi, cnt);
            }
            else {
                cnt = 0;
            }
        }

        return maxi;
    }
};

int main() {

    MaxConsecutiveOnes solver;

    vector<int> nums = {1,1,0,1,1,1};

    cout << "--- Brute Force ---" << endl;
    cout << solver.findMaxConsecutiveOnes_brute(nums) << endl;

    cout << endl;

    cout << "--- Optimal Approach ---" << endl;
    cout << solver.findMaxConsecutiveOnes_optimal(nums) << endl;

    return 0;
}