#include <bits/stdc++.h>
using namespace std;

vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> vis;

    pq.push({A[0] + B[0], {0, 0}});
    vis.insert({0, 0});

    vector<int> ans;

    while (K--) {

        auto top = pq.top();
        pq.pop();

        int sum = top.first;
        int i = top.second.first;
        int j = top.second.second;

        ans.push_back(sum);

        if (i + 1 < N && vis.find({i + 1, j}) == vis.end()) {
            pq.push({A[i + 1] + B[j], {i + 1, j}});
            vis.insert({i + 1, j});
        }

        if (j + 1 < N && vis.find({i, j + 1}) == vis.end()) {
            pq.push({A[i] + B[j + 1], {i, j + 1}});
            vis.insert({i, j + 1});
        }
    }

    return ans;
}

int main() {

    vector<int> A = {3, 2};
    vector<int> B = {1, 4};

    int N = 2;
    int K = 2;

    vector<int> ans = maxCombinations(N, K, A, B);

    for (int x : ans)
        cout << x << " ";

    return 0;
}