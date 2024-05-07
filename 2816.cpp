#include <iostream>
#include <stack>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if(!head) {
            return head;
        }
        ListNode* new_head = new ListNode;
        new_head->next = head;
        std::stack<int> numbers_stack;
        while(head) {
            numbers_stack.push(head->val);
            head = head->next;
        }
        std::stack<int> new_numbers_stack;
        int plus = 0;
        while(!numbers_stack.empty()) {
            int number = numbers_stack.top();
            numbers_stack.pop();
            number *= 2;
            number += plus;
            if(number > 9) {
                plus = 1;
                number -= 10;
            }
            else {
                plus = 0;
            }
            new_numbers_stack.push(number);
        }
        if(plus == 1) {
            head = new_head;
            head->val = 1;
            head = head->next;
        }
        else {
            head = new_head->next;
            new_head = new_head->next;
        }
        while(head) {
            head->val = new_numbers_stack.top();
            new_numbers_stack.pop();
            head = head->next;
        }
        return new_head;
    }
};

int main() {
    ListNode* head1 = new ListNode(1);
    ListNode* node11 = new ListNode(8);
    ListNode* node12 = new ListNode(9);
    head1->next = node11;
    node11->next = node12;

    ListNode* head2 = new ListNode(9);
    ListNode* node21 = new ListNode(9);
    ListNode* node22 = new ListNode(9);
    head2->next = node21;
    node21->next = node22;

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