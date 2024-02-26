#include <iostream>
#include <vector>
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
    bool isPalindrome(ListNode* head) {
        vector<int> numbers;
        int count = 0;
        while(head) {
            numbers.push_back(head->val);
            count++;
            head = head->next;
        }
        int n = numbers.size();
        for(int i = 0; i < n / 2; i++) {
            if(numbers[i] != numbers[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    ListNode* head1 = new ListNode(1);
    ListNode* node11 = new ListNode(2);
    ListNode* node12 = new ListNode(2);
    ListNode* node13 = new ListNode(1);
    head1->next = node11;
    node11->next = node12;
    node12->next = node13;
    ListNode* head2 = new ListNode(1);
    ListNode* node21 = new ListNode(2);
    head2->next = node21;

    Solution solution;

    bool solution1 = solution.isPalindrome(head1);
    bool solution2 = solution.isPalindrome(head2);

    cout << solution1  << endl;
    cout << solution2;

    return 0;
}