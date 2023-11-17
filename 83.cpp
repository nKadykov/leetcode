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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        while(temp && temp->next) {
            if(temp->val != temp->next->val) {
                temp = temp->next;
            }
            else {
                temp->next = temp->next->next;
            }
        }
        return head;
    }
};

int main() {
    ListNode* head1 = new ListNode(1);
    ListNode* temp11 = new ListNode(1);
    ListNode* temp12 = new ListNode(2);
    head1->next = temp11;
    temp11->next = temp12;
    
    ListNode* head2 = new ListNode(1);
    ListNode* temp21 = new ListNode(1);
    ListNode* temp22 = new ListNode(2);
    ListNode* temp23 = new ListNode(3);
    ListNode* temp24 = new ListNode(3);
    head2->next = temp21;
    temp21->next = temp22;
    temp22->next = temp23;
    temp23->next = temp24;

    Solution solution;

    ListNode* solution1 = solution.deleteDuplicates(head1);
    ListNode* solution2 = solution.deleteDuplicates(head2);

    while(solution1) {
        cout << solution1->val << ' ';
        solution1 = solution1->next;
    }
    cout << '\n';

    while(solution2) {
        cout << solution2->val << ' ';
        solution2 = solution2->next;
    }
}