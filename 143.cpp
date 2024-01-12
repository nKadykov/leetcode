#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        vector<ListNode*> nodes;
        while(temp != NULL && temp->next != NULL) {
            nodes.push_back(temp);
            temp = temp->next;
        }
        nodes.push_back(temp);
        int i = 0;
        int j = nodes.size() - 1;
        head = nodes[i];
        head->next = nodes[j];
        i++;
        temp = head->next;
        while(j > i) {
            temp->next = nodes[i];
            temp = temp->next;
            j--;
            temp->next = nodes[j];
            temp = temp->next;
            i++;
        }
        temp->next = NULL;
    }
};

int main() {
    ListNode* head1 = new ListNode(1);
    ListNode* node11 = new ListNode(2);
    ListNode* node12 = new ListNode(3);
    ListNode* node13 = new ListNode(4);
    head1->next = node11;
    node11->next = node12;
    node12->next = node13;

    ListNode* head2 = new ListNode(1);
    ListNode* node21 = new ListNode(2);
    ListNode* node22 = new ListNode(3);
    ListNode* node23 = new ListNode(4);
    ListNode* node24 = new ListNode(5);
    head2->next = node21;
    node21->next = node22;
    node22->next = node23;
    node23->next = node24;

    Solution solution;

    solution.reorderList(head1);
    solution.reorderList(head2);

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