#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class MergeSortedLists {
public:

    // Better Approach
    // Time Complexity : O(N + M)
    // Space Complexity : O(N + M)
    ListNode* mergeLists_better(ListNode* list1, ListNode* list2) {

        vector<int> arr;

        while (list1 != NULL) {
            arr.push_back(list1->val);
            list1 = list1->next;
        }

        while (list2 != NULL) {
            arr.push_back(list2->val);
            list2 = list2->next;
        }

        sort(arr.begin(), arr.end());

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        for (int x : arr) {
            temp->next = new ListNode(x);
            temp = temp->next;
        }

        return dummy->next;
    }

    // Optimal Approach
    // Time Complexity : O(N + M)
    // Space Complexity : O(1)
    ListNode* mergeLists_optimal(ListNode* l1, ListNode* l2) {

    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    if(l1->val > l2->val) {
        swap(l1, l2);
    }

    ListNode* res = l1;

    while(l1 != NULL && l2 != NULL) {

        ListNode* t = NULL;

        while(l1 != NULL && l1->val <= l2->val) {
            t = l1;
            l1 = l1->next;
        }

        t->next = l2;
        swap(l1, l2);
    }

    return res;
}
};

ListNode* createList(vector<int>& arr) {

    if (arr.empty()) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

void printList(ListNode* head) {

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    MergeSortedLists solver;

    vector<int> arr1 = {1, 2, 4};
    vector<int> arr2 = {1, 3, 4};

    ListNode* list1 = createList(arr1);
    ListNode* list2 = createList(arr2);

    cout << "--- Better Approach ---" << endl;
    ListNode* merged1 = solver.mergeLists_better(list1, list2);
    printList(merged1);

    cout << endl;

    list1 = createList(arr1);
    list2 = createList(arr2);

    cout << "--- Optimal Approach ---" << endl;
    ListNode* merged2 = solver.mergeLists_optimal(list1, list2);
    printList(merged2);

    return 0;
}