#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* temp = head->next;
        head->next = swapPairs(temp->next);
        temp->next = head;
        return temp;
    }
};

int main() {
    ListNode* head1 = new ListNode(1);
    ListNode* next11 = new ListNode(2);
    ListNode* next12 = new ListNode(3);
    ListNode* next13 = new ListNode(4);
    head1->next = next11;
    next11->next = next12;
    next12->next = next13;

    ListNode* head2 = new ListNode;

    ListNode* head3 = new ListNode(1);

    Solution solution;

    ListNode* solution1 = solution.swapPairs(head1);
    ListNode* solution2 = solution.swapPairs(head2);
    ListNode* solution3 = solution.swapPairs(head3);

    while(solution1) {
        cout << solution1->val << ' ';
        solution1 = solution1->next;
    }
    cout << '\n';
    while(solution2) {
        cout << solution2->val << ' ';
        solution2 = solution2->next;
    }
    cout << '\n';
    while(solution3) {
        cout << solution3->val << ' ';
        solution3 = solution3->next;

    }
    
    return 0;
}