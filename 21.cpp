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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy, *temp;
        dummy = new ListNode();
        temp = dummy;

        while(list1 && list2) {
            if(list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if(list1) {
            temp->next = list1;
        }
        if(list2) {
            temp->next = list2;
        }

        return dummy->next;
    }
};

int main() {
    ListNode* list1 = new ListNode(1);

    ListNode* temp1 = new ListNode(2);
    list1->next = temp1;

    ListNode* temp2 = new ListNode(4);
    temp1->next = temp2;

    while(list1) {
        cout << list1->val << ' ';
        list1 = list1->next;
    }

    cout << '\n';

    ListNode* list2 = new ListNode(1);

    ListNode* temp3 = new ListNode(3);
    list2->next = temp3;

    ListNode* temp4 = new ListNode(4);
    temp3->next = temp4;

    while(list2) {
        cout << list2->val << ' ';
        list2 = list2->next;
    }
    cout << '\n';

    Solution sol;

    ListNode* solution1;
    solution1 = sol.mergeTwoLists(list1, list2);
    while(solution1) {
        cout << solution1->val << ' ';
        solution1 = solution1->next;
    }

    return 0;
}