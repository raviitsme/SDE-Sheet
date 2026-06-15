#include <bits/stdc++.h>
using namespace std;

struct Meeting {
    int start;
    int end;
    int pos;
};

bool compare(Meeting a, Meeting b) {
    if(a.end == b.end)
        return a.pos < b.pos;
    return a.end < b.end;
}

vector<int> maxMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<Meeting> meetings;

    for(int i = 0; i < n; i++) {
        meetings.push_back({start[i], end[i], i + 1});
    }

    sort(meetings.begin(), meetings.end(), compare);

    vector<int> ans;
    int lastEnd = meetings[0].end;
    ans.push_back(meetings[0].pos);

    for(int i = 1; i < n; i++) {
        if(meetings[i].start > lastEnd) {
            ans.push_back(meetings[i].pos);
            lastEnd = meetings[i].end;
        }
    }

    return ans;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};

    vector<int> res = maxMeetings(start, end);

    cout << "Meetings selected: ";
    for(int x : res) cout << x << " ";
    cout << endl;

    return 0;
}