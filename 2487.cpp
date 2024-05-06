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
    ListNode* removeNodes(ListNode* head) {
        ListNode* current_node = head;
        std::stack<ListNode*> nodes_stack;
        while(current_node) {
            while (!nodes_stack.empty() && nodes_stack.top()->val < current_node->val) {
                nodes_stack.pop();
            }
            nodes_stack.push(current_node);
            current_node = current_node->next;
        }
        
        ListNode* next_node = nullptr;
        while(!nodes_stack.empty()) {
            current_node = nodes_stack.top();
            nodes_stack.pop();
            current_node->next = next_node;
            next_node = current_node;
        }
        return current_node;
    }
};

int main() {
    ListNode* head1 = new ListNode(5);
    ListNode* node11 = new ListNode(2);
    ListNode* node12 = new ListNode(13);
    ListNode* node13 = new ListNode(3);
    ListNode* node14 = new ListNode(8);
    head1->next = node11;
    node11->next = node12;
    node12->next = node13;
    node13->next = node14;

    ListNode* head2 = new ListNode(1);
    ListNode* node21 = new ListNode(1);
    ListNode* node22 = new ListNode(1);
    ListNode* node23 = new ListNode(1);
    head2->next = node21;
    node21->next = node22;
    node22->next = node23;

    Solution solution;

    ListNode* solution1 = solution.removeNodes(head1);
    ListNode* solution2 = solution.removeNodes(head2);

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