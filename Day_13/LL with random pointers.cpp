#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
private:
    void insertCopyInBetween(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* copyNode = new Node(temp->val);

            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }
    }

    void connectRandomPointers(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* copyNode = temp->next;
            if (temp->random) {
                copyNode->random = temp->random->next;
            } else {
                copyNode->random = nullptr;
            }
            temp = temp->next->next;
        }
    }

    Node* getDeepCopyList(Node* head) {
        Node* temp = head;
        Node* dummyHead = new Node(-1);
        Node* res = dummyHead;

        while (temp != NULL) {
            res->next = temp->next;
            res = res->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummyHead->next;
    }

public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;

        insertCopyInBetween(head);
        connectRandomPointers(head);

        return getDeepCopyList(head);
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "Node(" << temp->val << ") ";

        if (temp->random)
            cout << "Random->" << temp->random->val << endl;
        else
            cout << "Random->NULL" << endl;

        temp = temp->next;
    }
    cout << endl;
}

int main() {

    Solution obj;

    // Creating example list:
    // 1 -> 2 -> 3 -> NULL
    // random pointers:
    // 1 -> 3
    // 2 -> 1
    // 3 -> 2

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head->random = head->next->next;       // 1 -> 3
    head->next->random = head;             // 2 -> 1
    head->next->next->random = head->next;  // 3 -> 2

    cout << "Original List:\n";
    printList(head);

    Node* copiedHead = obj.copyRandomList(head);

    cout << "Copied List:\n";
    printList(copiedHead);

    return 0;
}