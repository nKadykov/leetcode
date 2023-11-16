#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int number = digits.size();
        for(int i = number - 1; i >= 0; i--) {
            if(i == number - 1)
                digits[i]++;
            if(digits[i] == 10) {
                digits[i] = 0;
                if(i != 0) {
                    digits[i - 1]++;
                }
                else {
                    digits.push_back(0);
                    digits[0] = 1;
                }
            }
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