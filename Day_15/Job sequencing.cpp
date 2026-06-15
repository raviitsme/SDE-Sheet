#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

vector<int> jobSequencing(vector<Job>& jobs) {

    sort(jobs.begin(), jobs.end(), compare);

    int n = jobs.size();

    int maxDeadline = 0;
    for(int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    vector<int> slot(maxDeadline + 1, -1);

    int countJobs = 0;
    int totalProfit = 0;

    for(int i = 0; i < n; i++) {

        for(int j = jobs[i].deadline; j > 0; j--) {

            if(slot[j] == -1) {
                slot[j] = jobs[i].id;
                countJobs++;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    return {countJobs, totalProfit};
}

int main() {

    vector<Job> jobs = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}
    };

    vector<int> ans = jobSequencing(jobs);

    cout << "Jobs done: " << ans[0] << endl;
    cout << "Total profit: " << ans[1] << endl;

    return 0;
}