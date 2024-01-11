#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* prev = head;
        ListNode* pos = head;
        while(pos != NULL && pos->next != NULL) {
            prev = prev->next;
            pos = pos->next->next;
            if(prev == pos) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    ListNode* head1 = new ListNode(3);
    ListNode* node11 = new ListNode(2);
    ListNode* node12 = new ListNode(0);
    ListNode* node13 = new ListNode(4);
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

    bool solution1 = solution.hasCycle(head1);
    bool solution2 = solution.hasCycle(head2);
    bool solution3 = solution.hasCycle(head3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}