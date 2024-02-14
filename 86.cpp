#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode();
        ListNode* temp1 = dummy1;
        ListNode* dummy2 = new ListNode();
        ListNode* temp2 = dummy2;
        while(head != NULL) {
            if(head->val < x) {
                temp1->next = head;
                temp1 = temp1->next;
            }
            else {
                temp2->next = head;
                temp2 = temp2->next;
            }
            head = head->next;
        }
        if(dummy1->next == NULL) {
            return dummy2->next;
        }
        temp1->next = dummy2->next;
        temp2->next = NULL;
        return dummy1->next;
    }
};

int main() {
    ListNode* head1 = new ListNode(1);
    ListNode* node11 = new ListNode(4);
    ListNode* node12 = new ListNode(3);
    ListNode* node13 = new ListNode(2);
    ListNode* node14 = new ListNode(5);
    ListNode* node15 = new ListNode(2);
    head1->next = node11;
    node11->next = node12;
    node12->next = node13;
    node13->next = node14;
    node14->next = node15;
    int x1 = 3;

    ListNode* head2 = new ListNode(2);
    ListNode* node21 = new ListNode(1);
    head2->next = node21;
    int x2 = 2;

    Solution solution;

    ListNode* solution1 = solution.partition(head1, x1);
    ListNode* solution2 = solution.partition(head2, x2);

    while(head1) {
        cout << head1->val << ' ';
        head1 = head1->next;
    }
    cout << '\n';
    while(head2) {
        cout << head2->val << ' ';
        head2 = head2->next;
    }

    return 0;
}