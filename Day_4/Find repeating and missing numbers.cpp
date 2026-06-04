#include<bits/stdc++.h>
using namespace std;

class FindRepeatingAndMissingNumber{
public:
    vector<int> find_brute(vector<int> &arr){
        int n = arr.size();
        int repeating = -1, missing = -1;

        for(int i = 1; i <= n; i++){
            int c = 0;
            
            for(int j = 0; j < n; j++) {
                if(arr[j] == i){
                    c++;
                }
            }

            if(c == 2) repeating = i;
            else if(c == 0) missing = i;

            if(repeating != -1 && missing != -1) {
                break;
            }
        }
        return {repeating, missing};
    }

    vector<int> find_better(vector<int> &arr){
        int n = arr.size(); 
        
        int hash[n + 1] = {0};
        
        for (int i = 0; i < n; i++) {
            hash[arr[i]]++;
        }

        int repeating = -1, missing = -1;
        
        for (int i = 1; i <= n; i++) {
            if (hash[i] == 2) {
                repeating = i;
            } else if (hash[i] == 0) {
                missing = i;
            }

            if (repeating != -1 && missing != -1) {
                break;
            }
        }
        
        return {repeating, missing};
    }

    vector<int> find_optimal(vector<int> &arr) {
        long long n = arr.size();

        long long Sn = (n * (n + 1)) / 2;
        long long S2n = (n * (n + 1) * (2 * n + 1)) / 6;

        long long S = 0, S2 = 0;
        for (int i = 0; i < n; i++) {
            S += arr[i];
            S2 += (long long)arr[i] * (long long)arr[i];
        }

        long long val1 = S - Sn; 
        long long val2 = S2 - S2n; 

        val2 = val2 / val1; 

        long long repeating = (val1 + val2) / 2;
        long long missing = val2 - repeating;

        return {(int)repeating, (int)missing};
    }

    vector<int> find_xor_optimal(vector<int> &arr) {
        int n = arr.size();
        int xr = 0;

        for (int i = 0; i < n; i++) {
            xr = xr ^ arr[i];
            xr = xr ^ (i + 1);
        }

        int number = xr & ~(xr - 1); 

        int zero = 0;
        int one = 0;

        for (int i = 0; i < n; i++) {
            if ((arr[i] & number) != 0) {
                one = one ^ arr[i];
            } else {
                zero = zero ^ arr[i];
            }
            
            if (((i + 1) & number) != 0) {
                one = one ^ (i + 1);
            } else {
                zero = zero ^ (i + 1);
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == zero) count++;
        }

        if (count == 2) return {zero, one}; 
        return {one, zero}; 
    }

    void printArray(vector<int> &arr) {
        int n = arr.size();
        for(auto i : arr){
            cout << i << " ";
        }
    }
};

int main() {
    FindRepeatingAndMissingNumber sol;

    vector<int> ans(2, 0);
    vector<int> arr = {1, 2, 3, 4, 4, 5};

    cout << "Answer using brute : " << endl;
    ans = sol.find_brute(arr);
    sol.printArray(ans);
    ans.clear();
    
    cout << "\n";


    cout << "Answer using better : " << endl;
    ans = sol.find_better(arr);
    sol.printArray(ans);
    ans.clear();
    
    cout << "\n";

}