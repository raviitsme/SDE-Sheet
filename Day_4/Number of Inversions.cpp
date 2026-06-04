#include <bits/stdc++.h>
using namespace std;

class NumberOfInversions {
private:
    long long mergeAndCount(vector<int> &a, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        long long count = 0;

        while (left <= mid && right <= high) {
            if (a[left] <= a[right]) {
                temp.push_back(a[left]);
                left++;
            } else {
                temp.push_back(a[right]);
                count += (mid - left + 1);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(a[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(a[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            a[i] = temp[i - low];
        }

        return count;
    }

    long long mergeSortAndCount(vector<int> &a, int low, int high) {
        long long count = 0;
        if (low >= high) return count;

        int mid = low + (high - low) / 2;

        count += mergeSortAndCount(a, low, mid);
        count += mergeSortAndCount(a, mid + 1, high);
        count += mergeAndCount(a, low, mid, high);

        return count;
    }

public:
    int solution_brute(vector<int>& a, int n) {
        int c = 0; 
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] > a[j]) c++; 
            }
        }
        return c; 
    }

    long long solution_optimal(vector<int>& a, int n) {
        return mergeSortAndCount(a, 0, n - 1);
    }
};

int main() {
    NumberOfInversions ni;
    
    vector<int> arr1 = {2, 4, 1, 3, 5};
    vector<int> arr2 = {2, 4, 1, 3, 5};
    int n = arr1.size();

    cout << "Brute Force Inversions: " << ni.solution_brute(arr1, n) << endl;
    cout << "Optimal Method Inversions: " << ni.solution_optimal(arr2, n) << endl;

    return 0;
}