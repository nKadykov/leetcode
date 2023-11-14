#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
public:
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        int number1, number2, sum, remainder, firstNumber = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        while(list1 || list2 || firstNumber != 0) {
            number1 = (list1 != nullptr) ? list1->val : 0;
            number2 = (list2 != nullptr) ? list2->val : 0;
            sum = number1 + number2;
            remainder = sum % 10;
            firstNumber = sum / 10;
            ListNode* temp = new ListNode(remainder);
            head->next = temp;
            head = head->next;
            list1 = (list1 != nullptr) ? list1->next : nullptr;
            list2 = (list2 != nullptr) ? list2->next : nullptr;
        }
        return dummy->next;
    }
};

int main() {
    ListNode* list1 = new ListNode(2);
    ListNode* temp1 = new ListNode(4);
    list1->next = temp1;
    ListNode* temp2 = new ListNode(3);
    temp1->next = temp2;
    while(list1) {
        cout << list1->val << ' ';
        list1 = list1->next;
    }
    cout << '\n';

    ListNode* list2 = new ListNode(5);
    ListNode* temp3 = new ListNode(6);
    list2->next = temp3;
    ListNode* temp4 = new ListNode(4);
    temp3->next = temp4;
    while(list2) {
        cout << list2->val << ' ';
        list2 = list2->next;
    }

    Solution sol;

    ListNode* solution1 = sol.addTwoNumbers(list1, list2);
    while(solution1) {
        cout << solution1->val << ' ';
        solution1 = solution1->next;
    }

    return 0;
}