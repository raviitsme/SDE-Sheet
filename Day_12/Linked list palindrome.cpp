#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    
    ListNode(int x) {
        val = x;
        next = NULL;
    };
};

class PalindromeLinkedList {
private:

    // Helper function to reverse a Linked List
    ListNode* reversedLinkedList(ListNode* head) {
        ListNode* prev = NULL, *curr = head, *next;
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        } 
        return prev;
    }
public:

    // Brute Force | TC - O(2N) SC - O(N)
    
    bool isPalindrome_brute(ListNode* head) {

        stack<int> st;

        ListNode* temp = head;

        while (temp != NULL) {
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;

        while (temp != NULL) {

            if (temp->val != st.top()) {
                return false;
            }

            st.pop();
            temp = temp->next;
        }

        return true;
    }

    // Optimal code | TC - O(2N) SC - O(1)
    bool isPalindrome_optimal(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast -> next != NULL && fast -> next -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* newHead = reversedLinkedList(slow -> next);
        ListNode* first = head;
        ListNode* second = newHead;

        while(second != NULL) {
            if(first -> val != second -> val) {
                reversedLinkedList(newHead);
                return false;
            }
            first = first -> next;
            second = second -> next;
        }
        reversedLinkedList(newHead);
        return true;
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

int main() {

    PalindromeLinkedList solver;

    vector<int> arr = {1, 2, 3, 2, 1};

    ListNode* head1 = createList(arr);
    ListNode* head2 = createList(arr);

    cout << "--- Brute Force ---" << endl;
    if (solver.isPalindrome_brute(head1))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    cout << endl;

    cout << "--- Optimal Approach ---" << endl;
    if (solver.isPalindrome_optimal(head2))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}