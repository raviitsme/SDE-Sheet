#include <bits/stdc++.h>
using namespace std;

int findPlatform(vector<int>& arr, vector<int>& dep) {

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int n = arr.size();

    int i = 0, j = 0;
    int platforms = 0, maxPlatforms = 0;

    while(i < n && j < n) {

        if(arr[i] <= dep[j]) {
            platforms++;
            i++;
        }
        else {
            platforms--;
            j++;
        }

        maxPlatforms = max(maxPlatforms, platforms);
    }

    return maxPlatforms;
}

int main() {

    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    cout << "Minimum platforms needed: " 
         << findPlatform(arr, dep) << endl;

    return 0;
}