#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* first = head;
        ListNode* second = head;

        while(second && second->next) {
            first = first->next;
            second = second->next->next;
            if(first == second) {
                first = head;
                while(first != second) {
                    first = first->next;
                    second = second->next;
                }
                return first;
            }
        }
        return nullptr;
    }
};

int main() {
    ListNode* head1 = new ListNode(3);
    ListNode* node11 = new ListNode(2);
    ListNode* node12 = new ListNode(0);
    ListNode* node13 = new ListNode(-4);
    head1->next = node11;
    node11->next = node12;
    node12->next = node13;
    node13->next = node11;

    ListNode* head2 = new ListNode(1);
    ListNode* node21 = new ListNode(2);
    head2->next = node21;
    node21->next = head2;

    ListNode* head3 = new ListNode(1);

    Solution solution;

    ListNode* solution1 = solution.detectCycle(head1);
    ListNode* solution2 = solution.detectCycle(head2);
    ListNode* solution3 = solution.detectCycle(head3);

    return 0;
}