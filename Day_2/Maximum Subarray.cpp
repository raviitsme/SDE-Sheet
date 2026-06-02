#include<bits/stdc++.h>
using namespace std;

class MaxSumSubarray {
public :
    // Brute force solution
    int maxSubarraySum_brute(vector<int> &nums){
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                int sum = 0;
                for(int k = i; k <= j; k++) {
                    sum += nums[k];
                }
                maxi = max(sum, maxi);
            }
        }
        return maxi;
    }


    // Better solution :
    int maxSubarraySum_better(vector<int> &nums) {
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for(int j = i; j < nums.size(); j++) {
                sum += nums[j];
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }

    // Using Kadane's Algorithm
    int kadanesAlgorithm(vector<int> &nums) {
        int maxi = INT_MIN;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum > maxi) {
                maxi = sum;
            } 
            if(sum < 0) {
                sum = 0;
            }
        }
        return maxi;
    }
};

int main() {
    MaxSumSubarray solver;

    // Example array: The maximum subarray is [4, -1, 2, 1] with a sum of 6
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "=== Testing Maximum Subarray Sum ===" << endl;
    cout << "Input Array: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << "\n\n";

    // 1. Testing Brute Force Approach
    int bruteResult = solver.maxSubarraySum_brute(nums);
    cout << "1. Brute Force Result : " << bruteResult << " (Expected: 6)" << endl;

    // 2. Testing Better Approach
    int betterResult = solver.maxSubarraySum_better(nums);
    cout << "2. Better Method Result: " << betterResult << " (Expected: 6)" << endl;

    // 3. Testing Kadane's Algorithm (Optimal)
    int optimalResult = solver.kadanesAlgorithm(nums);
    cout << "3. Kadane's Algorithm  : " << optimalResult << " (Expected: 6)" << endl;

    return 0;
}