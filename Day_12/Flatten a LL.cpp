#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *child;

    Node(int x) {
        data = x;
        next = nullptr;
        child = nullptr;
    }
};

class FlattenLinkedList {
private:

    Node* mergeList(Node* l1, Node* l2) {

        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;

        while (l1 != NULL && l2 != NULL) {

            if (l1->data < l2->data) {
                res->child = l1;
                res = l1;
                l1 = l1->child;
            }
            else {
                res->child = l2;
                res = l2;
                l2 = l2->child;
            }

            res->next = NULL;
        }

        if (l1)
            res->child = l1;
        else
            res->child = l2;

        if (dummyNode->child)
            dummyNode->child->next = NULL;

        return dummyNode->child;
    }

public:

    // Optimal Approach
    // Time Complexity : O(N * M)
    // Space Complexity : O(N)

    Node* flattenLinkedList(Node* head) {

        if (head == NULL || head->next == NULL)
            return head;

        Node* mergedHead = flattenLinkedList(head->next);

        head = mergeList(head, mergedHead);

        return head;
    }
};

void printFlattened(Node* head) {

    while (head != NULL) {
        cout << head->data << " ";
        head = head->child;
    }

    cout << endl;
}

int main() {

    FlattenLinkedList solver;

    Node* head = new Node(5);

    head->child = new Node(7);
    head->child->child = new Node(8);
    head->child->child->child = new Node(30);

    head->next = new Node(10);
    head->next->child = new Node(20);

    head->next->next = new Node(19);
    head->next->next->child = new Node(22);
    head->next->next->child->child = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->child = new Node(35);
    head->next->next->next->child->child = new Node(40);
    head->next->next->next->child->child->child = new Node(45);

    Node* flatHead = solver.flattenLinkedList(head);

    cout << "Flattened Linked List : ";
    printFlattened(flatHead);

    return 0;
}