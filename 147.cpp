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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        while(cur) {
            if((cur->next) && (cur->next->val < cur->val)) {
                while((pre->next) && (pre->next->val < cur->next->val)) {
                    pre = pre->next;
                }
                ListNode* temp = pre->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = temp;
                pre = dummy;
            }
            else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};

int main() {
    ListNode* head1 = new ListNode(4);
    ListNode* node11 = new ListNode(2);
    ListNode* node12 = new ListNode(1);
    ListNode* node13 = new ListNode(3);
    head1->next = node11;
    node11->next = node12;
    node12->next = node13;

    ListNode* head2 = new ListNode(-1);
    ListNode* node21 = new ListNode(5);
    ListNode* node22 = new ListNode(3);
    ListNode* node23 = new ListNode(4);
    ListNode* node24 = new ListNode(0);
    head2->next = node21;
    node21->next = node22;
    node22->next = node23;
    node23->next = node24;

    Solution solution;

    head1 = solution.insertionSortList(head1);
    head2 = solution.insertionSortList(head2);

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