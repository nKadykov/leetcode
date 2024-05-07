#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    int multiply(ListNode* head) {
        if(!head) {
            return 0;
        }
        int new_number = head->val * 2 + multiply(head->next);
        head->val = new_number % 10;
        return new_number / 10;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        int plus = multiply(head);
        if(plus) {
            head = new ListNode(plus, head);
        }
        return head;
    }
};

int main() {
    ListNode* node12 = new ListNode(9);
    ListNode* node11 = new ListNode(8, node12);
    ListNode* head1 = new ListNode(1, node11);

    ListNode* node22 = new ListNode(9);
    ListNode* node21 = new ListNode(9, node22);
    ListNode* head2 = new ListNode(9, node21);

    Solution solution;

    ListNode* solution1 = solution.doubleIt(head1);
    ListNode* solution2 = solution.doubleIt(head2);

    while(solution1) {
        std::cout << solution1->val << ' ';
        solution1 = solution1->next;
    }
    std::cout << std::endl;
    while(solution2) {
        std::cout << solution2->val << ' ';
        solution2 = solution2->next;
    }

    return 0;
}