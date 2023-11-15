#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int& val) {
        int number = nums.size();
        int index = 0;
        for(auto& x : nums) {
            if(x != val) {
                nums[index] = x;
                index++;
            }
        }
        return index;
    }
};

int main() {
    vector<int> vector1 {3, 2, 2, 3};
    int val1 = 3;
    vector<int> vector2 {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;

    Solution solution;

    int solution1 = solution.removeElement(vector1, val1);
    int solution2 = solution.removeElement(vector2, val2);

    for(auto& x : vector1) {
        cout << x << ' ';
    }
    cout << '\n' << solution1 << '\n';
        for(auto& x : vector2) {
        cout << x << ' ';
    }
    cout << '\n' << solution2 << '\n';
    return 0;
}