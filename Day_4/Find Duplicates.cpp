#include<bits/stdc++.h>
using namespace std;

class FindDuplicates {
public:
    int find_duplicates_brute(vector<int> &nums){
        int duplicate = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == nums[i + 1]) {
                duplicate = nums[i];
                break;
            }
        }
        return duplicate;
    }

    int find_duplicates_better(vector<int> &nums){
        int n = nums.size();
        vector<int> dummyArr(n, 0);
        for(int i = 0; i < n; i++) {
            if(dummyArr[nums[i]] == 1) {
                return nums[i];
            } else {
                dummyArr[nums[i]] = 1;
            }
        }
        return -1;
    }

    // Optimal Solution (Floyd's Cycle Detection)
    int find_duplicates_optimal(vector<int> &nums){
        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        fast = nums[0];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }

};

int main() {
    FindDuplicates solution;

    vector<int> arr1 = {1,3,4,2,2};
    cout << "Duplicate using bruteforce :" << endl;
    int ans1 = solution.find_duplicates_brute(arr1);
    cout << "Duplicate : " << ans1 << " expected : 2" << endl;

    cout << endl;
    
    cout << "Duplicate using better :" << endl;
    int ans2 = solution.find_duplicates_better(arr1);
    cout << "Duplicate : " << ans2 << " expected : 2" << endl;

    cout << endl;

    cout << "Duplicate using optimized :" << endl;
    int ans3 = solution.find_duplicates_optimal(arr1);
    cout << "Duplicate : " << ans3 << " expected : 2" << endl;
}