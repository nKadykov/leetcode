#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* p = head;
        ListNode* q = NULL;
        int count = 1;
        while(count != left) {
            q = p;
            p = p->next;
            count++;
        }
        ListNode* curr = p->next;
        ListNode* prev = p;
        count++;
        while(count <= right) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(count < right) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(q != NULL) {
            q->next = prev;
        }
        else {
            head = prev;
        }
        if(p != NULL) {
            p->next = curr;
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
    int left1 = 2;
    int right1 = 4;

    ListNode* head2 = new ListNode(5);
    int left2 = 1;
    int right2 = 1;

    Solution solution;

    ListNode* solution1 = solution.reverseBetween(head1, left1, right1);
    ListNode* solution2 = solution.reverseBetween(head2, left2, right2);

    while(head1) {
        cout << head1->val << ' ';
        head1 = head1->next;
    }
    cout << '\n';
    while(head2) {
        cout << head2->val << ' ';
        head2 = head2->next;
    }

    return 0;
}