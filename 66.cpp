#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        deque<int> digitDeque;
        int number = digits.size();
        for(int i = 0; i < number; i++) {
            digitDeque.push_back(digits[i]);
        }
        if(digitDeque[number - 1] == 9 && number != 1) {
            digitDeque[number - 1] = 0;
            digitDeque[number - 2]++;
        }
        else {
            digitDeque[number - 1]++;
        }
        for(int i = number - 2; i > 0; i--) {
            if(digitDeque[i] == 10) {
                digitDeque[i] = 0;
                digitDeque[i - 1]++;
            }
        }
        if(number == 1) {
            if(digitDeque[0] >= 9) {
                digitDeque[0] = 0;
                digitDeque.push_front(1);
            }
        }
        else {
            if(digitDeque[0] >= 10) {
                digitDeque[0] = 0;
                digitDeque.push_front(1);
            }
        }
        for(int i = 0; i < digits.size(); i++) {
            digits[i] = digitDeque[i];
        }
        if(digitDeque.size() > number) {
            digits.push_back(digitDeque[number]);
        }
        return digits;
    }
};

int main() {
    vector<int> digits1 {1,2,3};
    vector<int> digits2 {4,3,2,1};
    vector<int> digits3 {9};

    Solution solution;

    vector<int> solution1 = solution.plusOne(digits1);
    vector<int> solution2 = solution.plusOne(digits2);
    vector<int> solution3 = solution.plusOne(digits3);

    for(auto& x : solution1) {
        cout << x;
    }
    cout << '\n';
    for(auto& x : solution2) {
        cout << x;
    }
    cout << '\n';
    for(auto& x : solution3) {
        cout << x;
    }

    return 0;
}