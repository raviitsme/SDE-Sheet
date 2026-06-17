#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {

        vector<int> nums;
        int fact = 1;

        for(int i = 1; i < n; i++) {
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n);

        k--;

        string ans = "";

        while(true) {

            int idx = k / fact;
            ans += to_string(nums[idx]);

            nums.erase(nums.begin() + idx);

            if(nums.empty()) break;

            k %= fact;
            fact /= nums.size();
        }

        return ans;
    }
};

int main() {
    Solution obj;

    cout << obj.getPermutation(3, 4);

    return 0;
}