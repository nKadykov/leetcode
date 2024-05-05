#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main() {
    ListNode* head1 = new ListNode(4);
    ListNode* node11 = new ListNode(5);
    ListNode* node12 = new ListNode(1);
    ListNode* node13 = new ListNode(9);
    head1->next = node11;
    node11->next = node12;
    node12->next = node13;

    ListNode* head2 = new ListNode(4);
    ListNode* node21 = new ListNode(5);
    ListNode* node22 = new ListNode(1);
    ListNode* node23 = new ListNode(9);
    head2->next = node21;
    node21->next = node22;
    node22->next = node23;

    Solution solution;

    solution.deleteNode(node11);
    solution.deleteNode(node22);

    while(head1) {
        std::cout << head1->val << ' ';
        head1 = head1->next;
    }
    std::cout << std::endl;
    while(head2) {
        std::cout << head2->val << ' ';
        head2 = head2->next;
    }

    return 0;
}