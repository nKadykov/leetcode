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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int number = 1;
        if(head == NULL && head->next == NULL) {
            return head;
        }
        while(head && head->next) {
            number++;
            head = head->next;
        }
        head = dummy->next;
        if(number == 1) {
            return 0;
        }
        number -= n;
        if(number == 0) {
            head = head->next;
            return head;
        }
        for(int i = 1; i < number; i++) {
            head = head->next;
        }
        if(head->next && head->next->next)
            head->next = head->next->next;
        else if(head->next) {
            head->next = NULL;
        }
        else {
            head = 0;
        }
        return dummy->next;
    }
};

int main() {
    ListNode* node11 = new ListNode(1);
    ListNode* node12 = new ListNode(2);
    ListNode* node13 = new ListNode(3);
    ListNode* node14 = new ListNode(4);
    ListNode* node15 = new ListNode(5);
    node11->next = node12;
    node12->next = node13;
    node13->next = node14;
    node14->next = node15;
    int n1 = 2;

    ListNode* node21 = new ListNode(1);
    int n2 = 1;

    ListNode* node31 = new ListNode(1);
    ListNode* node32 = new ListNode(2);
    node31->next = node32;
    int n3 = 1;

    Solution solution;

    ListNode* solution1 = solution.removeNthFromEnd(node11, n1);
    ListNode* solution2 = solution.removeNthFromEnd(node21, n2);
    ListNode* solution3 = solution.removeNthFromEnd(node31, n3);

    while(solution1 && solution1->next) {
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