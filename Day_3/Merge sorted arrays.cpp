#include<bits/stdc++.h>
using namespace std;

class MergeSortedArrays{
public:
    // Brute Force
    void merge_sort_brute(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        for(int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }

    // Better 
    void merge_sort_better(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> temp(m + n);
        int p1 = 0, p2 = 0, k = 0;

        while(p1 < m && p2 < n) {
            if(nums1[p1] <= nums2[p2]) {
                temp[k++] = nums1[p1++];
            } else {
                temp[k++] = nums2[p2++];
            }
        }
        while(p1 < m) temp[k++] = nums1[p1++];
        while(p2 < n) temp[k++] = nums2[p2++];
        nums1 = temp;
    }
    void merge_sort_optimized(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int k = m + n - 1;
        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        while(j >= 0){
            nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    MergeSortedArrays msa;

    // Test Case: m = 3 (actual elements), n = 3 (empty spaces at the back of nums1)
    int m = 3;
    int n = 3;

    // Alag-alag vectors banayein taaki har method ko fresh input mile
    vector<int> nums1_brute = {1, 2, 3, 0, 0, 0};
    vector<int> nums1_better = {1, 2, 3, 0, 0, 0};
    vector<int> nums1_optimized = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};

    cout << "Original Arrays:" << endl;
    cout << "nums1: [1, 2, 3, 0, 0, 0]" << endl;
    cout << "nums2: [2, 5, 6]" << endl << endl;

    // 1. Testing Brute Force Approach
    msa.merge_sort_brute(nums1_brute, m, nums2, n);
    cout << "=== Brute Force Result ===" << endl;
    cout << "Merged: ";
    for (int num : nums1_brute) cout << num << " ";
    cout << "\n\n";

    // 2. Testing Better Approach
    msa.merge_sort_better(nums1_better, m, nums2, n);
    cout << "=== Better Approach Result ===" << endl;
    cout << "Merged: ";
    for (int num : nums1_better) cout << num << " ";
    cout << "\n\n";

    // 3. Testing Optimized Approach
    msa.merge_sort_optimized(nums1_optimized, m, nums2, n);
    cout << "=== Optimized Approach Result ===" << endl;
    cout << "Merged: ";
    for (int num : nums1_optimized) cout << num << " ";
    cout << endl;

    return 0;
}