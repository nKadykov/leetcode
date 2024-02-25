#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
};

int main() {
    ListNode* head1 = new ListNode(1);
    ListNode* node11 = new ListNode(2);
    ListNode* node12 = new ListNode(3);
    ListNode* node13 = new ListNode(4);
    ListNode* node14 = new ListNode(5);
    head1->next = node11;
    node11->next = node12;
    node12->next = node13;
    node13->next = node14;

    ListNode* head2 = new ListNode(1);
    ListNode* node21 = new ListNode(2);
    head2->next = node21;

    Solution solution;

    ListNode* solution1 = solution.reverseList(head1);
    ListNode* solution2 = solution.reverseList(head2);

    while(solution1) {
        cout << solution1->val << ' ';
        solution1 = solution1->next;
    }
    cout << endl;
    while(solution2) {
        cout << solution2->val << ' ';
        solution2 = solution2->next;
    }

    return 0;
}