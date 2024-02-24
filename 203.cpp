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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* d = new ListNode;
        ListNode* dummy = d;
        dummy->next = head;
        while(dummy && dummy->next) {
            if(dummy->next->val == val) {
                dummy->next = dummy->next->next;
            }
            else {
                dummy = dummy->next;
            }
        }
        return d->next;
    }
};

int main() {
    ListNode* head1 = new ListNode(1);
    ListNode* node11 = new ListNode(2);
    ListNode* node12 = new ListNode(6);
    ListNode* node13 = new ListNode(3);
    ListNode* node14 = new ListNode(4);
    ListNode* node15 = new ListNode(5);
    ListNode* node16 = new ListNode(6);
    head1->next = node11;
    node11->next = node12;
    node12->next = node13;
    node13->next = node14;
    node14->next = node15;
    node15->next = node16;
    int val1 = 6;

    // ListNode* head2;
    // int val2 = 1;

    ListNode* head3 = new ListNode(7);
    ListNode* node31 = new ListNode(7);
    ListNode* node32 = new ListNode(7);
    ListNode* node33 = new ListNode(7);
    head3->next = node31;
    node31->next = node32;
    node32->next = node33;
    int val3 = 7;

    Solution solution;

    ListNode* solution1 = solution.removeElements(head1, val1);
    // ListNode* solution2 = solution.removeElements(head2, val2);
    ListNode* solution3 = solution.removeElements(head3, val3);

    while(solution1) {
        cout << solution1->val << ' ';
        solution1 = solution1->next;
    }
    cout << '\n';
    // while(solution2) {
    //     cout << solution2->next << ' ';
    //     solution2 = solution2->next;
    // }
    cout << '\n';
    while(solution3) {
        cout << solution3->val << ' ';
        solution3 = solution3->next;
    }
    
    return 0;
}