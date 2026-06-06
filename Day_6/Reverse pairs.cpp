#include <bits/stdc++.h>
using namespace std;

class ReversePairs {
private:
    // Helper function to count pairs across two sorted halves
    int countPairs(vector<int> &nums, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;
        
        for (int i = low; i <= mid; i++) {
            // Using 2LL (long long) to prevent integer overflow when multiplying by 2
            while (right <= high && nums[i] > 2LL * nums[right]) {
                right++;
            }
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    // Standard Merge function to combine two sorted halves
    void merge(vector<int> &nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    // Modified Merge Sort function
    int mergeSort(vector<int> &nums, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        
        int mid = low + (high - low) / 2;
        
        cnt += mergeSort(nums, low, mid);       // Left half pairs
        cnt += mergeSort(nums, mid + 1, high);   // Right half pairs
        cnt += countPairs(nums, low, mid, high); // Cross pairs count
        merge(nums, low, mid, high);             // Actual sorting step
        
        return cnt;
    }

public:
    // 1. Brute Force Approach - O(N^2) Time | O(1) Space
    int reversePairs_brute(vector<int> &nums) {
        int n = nums.size();
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // 2LL prevents overflow if nums[j] is very large or INT_MAX
                if (nums[i] > 2LL * nums[j]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }

    // 2. Optimized Approach (Merge Sort Based) - O(N log N) Time | O(N) Space
    int reversePairs_optimized(vector<int> &nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main() {
    ReversePairs solver;
    
    // Test Case
    vector<int> arr1 = {1, 3, 2, 3, 1};
    vector<int> arr2 = arr1; // Duplicate array for optimized method since merge sort modifies it
    
    // Testing Brute Force
    cout << "Answer using brute     : " << solver.reversePairs_brute(arr1) << endl;
    
    // Testing Optimized (Merge Sort)
    cout << "Answer using optimized : " << solver.reversePairs_optimized(arr2) << endl;
    
    return 0;
}