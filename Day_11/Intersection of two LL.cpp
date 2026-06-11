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

class IntersectionPoint {
private:
    ListNode* collisionPoint(ListNode* t1, ListNode* t2, int d) {
        while(d) {
            d--;
            t2 = t2 -> next;
        }
        while(t1 != t2) {
            t1 = t1 -> next;
            t2 = t2 -> next;
        }
        return t1;
    }

public:

    // Brute Force (HashMap)
    // Time Complexity : O(N + M)
    // Space Complexity : O(N + M)
    ListNode* getIntersection_brute(ListNode* headA, ListNode* headB) {

        unordered_map<ListNode*, int> mp;

        ListNode* temp = headA;

        while (temp != NULL) {
            mp[temp] = 1;
            temp = temp->next;
        }

        temp = headB;

        while (temp != NULL) {
            if (mp.find(temp) != mp.end()) {
                return temp;
            }
            temp = temp->next;
        }

        return NULL;
    }

    // Better Approach (Length Difference)
    // Time Complexity : O(N + 2M)
    // Space Complexity : O(1)


ListNode* getIntersection_better(ListNode* headA, ListNode* headB) {

    int lenA = 0, lenB = 0;

    ListNode* t1 = headA;
    ListNode* t2 = headB;

    while (t1 != NULL) {
        lenA++;
        t1 = t1->next;
    }

    while (t2 != NULL) {
        lenB++;
        t2 = t2->next;
    }

    if (lenA < lenB) {
        return collisionPoint(headA, headB, lenB - lenA);
    }

    return collisionPoint(headB, headA, lenA - lenB);
}

    // Optimal Approach (Pointer Switching)
    // Time Complexity : O(N + M)
    // Space Complexity : O(1)
    ListNode *getIntersection_optimal(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        
        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while(t1 != t2){
            t1 = t1 -> next;
            t2 = t2 -> next;

            if(t1 == t2) return t1;

            if(t1 == NULL) t1 = headB;
            if(t2 == NULL) t2 = headA;
        }
        return t1;
    }
};

int main() {

    IntersectionPoint solver;

    // Common Part
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    // List A
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    // List B
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    cout << "--- Brute Force ---" << endl;
    ListNode* ans1 = solver.getIntersection_brute(headA, headB);

    if (ans1)
        cout << "Intersection Node : " << ans1->val << endl;
    else
        cout << "No Intersection" << endl;

    cout << endl;

    cout << "--- Better Approach ---" << endl;
    ListNode* ans2 = solver.getIntersection_better(headA, headB);

    if (ans2)
        cout << "Intersection Node : " << ans2->val << endl;
    else
        cout << "No Intersection" << endl;

    cout << endl;

    cout << "--- Optimal Approach ---" << endl;
    ListNode* ans3 = solver.getIntersection_optimal(headA, headB);

    if (ans3)
        cout << "Intersection Node : " << ans3->val << endl;
    else
        cout << "No Intersection" << endl;

    return 0;
}