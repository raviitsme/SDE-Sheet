#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr, int students, int maxPages) {

    int count = 1;
    int pages = 0;

    for (int x : arr) {

        if (pages + x <= maxPages)
            pages += x;
        else {
            count++;
            pages = x;

            if (count > students)
                return false;
        }
    }

    return true;
}

int findPages(vector<int>& arr, int students) {

    if (students > arr.size())
        return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    int ans = -1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (isPossible(arr, students, mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {12, 34, 67, 90};

    cout << findPages(arr, 2);
}