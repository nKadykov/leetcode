#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> nums;
        ListNode* temp=head;
        while(temp != NULL){
            nums.push_back(temp->val);
            temp = temp->next;
        }
        sort(nums.begin(),nums.end());
        temp = head;
        int i = 0;
        while(temp != NULL){
            temp->val = nums[i];
            temp = temp->next;
            i++;
        }
        return head;
    }
};

int main() {
    ListNode* head1 = new ListNode(4);
    ListNode* node11 = new ListNode(2);
    ListNode* node12 = new ListNode(1);
    ListNode* node13 = new ListNode(3);
    head1->next = node11;
    node11->next = node12;
    node12->next = node13;
    
    ListNode* head2 = new ListNode(-1);
    ListNode* node21 = new ListNode(5);
    ListNode* node22 = new ListNode(3);
    ListNode* node23 = new ListNode(4);
    ListNode* node24 = new ListNode(0);
    head2->next = node21;
    node21->next = node22;
    node22->next = node23;
    node23->next = node24;

    Solution solution;

    head1 = solution.sortList(head1);
    head2 = solution.sortList(head2);

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