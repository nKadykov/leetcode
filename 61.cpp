#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void add(int x, ListNode *node);
    void print();
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int num = 1;
        ListNode* temp = head;
        if(!head || !head->next) {
            return head;
        }
        while(temp && temp->next) {
            num++;
            temp = temp->next;
        }
        for(int i = 0; i < k % num; i++) {
            ListNode* dummy = new ListNode;
            dummy->next = head;
            int next = head->next->val;
            int temp = head->val;
            while(head && head->next) {
                next = head->next->val;
                head->next->val = temp;
                temp = next;
                head = head->next;
            }
            dummy->next->val = temp;
            head = dummy->next;
            delete dummy;
        }
        return head;
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
    int k1 = 2;

    ListNode* head2 = new ListNode(0);
    ListNode* node21 = new ListNode(1);
    ListNode* node22 = new ListNode(2);
    head2->next = node21;
    node21->next = node22;
    int k2 = 4;

    Solution solution;

    ListNode* solution1 = solution.rotateRight(head1, k1);
    ListNode* solution2 = solution.rotateRight(head2, k2);

    while(solution1) {
        cout << solution1->val << ' ';
        solution1 = solution1->next;
    }
    cout << '\n';
    while(solution2) {
        cout << solution2->val << ' ';
        solution2 = solution2->next;
    }
    return 0;
}