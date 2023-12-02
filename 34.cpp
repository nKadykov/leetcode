#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int number = nums.size();
        int begin = -1, end = -1;
        vector<int> result;
        for(int i = 0; i < number; i++) {
            if(nums[i] == target) {
                begin = i;
                break;
            }
        }
        for(int i = number - 1; i >= 0; i--) {
            if(nums[i] == target && end != begin) {
                end = i;
                break;
            }
        }
        result.push_back(begin);
        result.push_back(end);
        return result;
    }
};

int main() {
    vector<int> vector1 {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    vector<int> vector2 {5, 7, 7, 8, 8, 10};
    int target2 = 6;
    vector<int> vector3;
    int target3 = 0;

    Solution solution;

    vector<int> solution1 = solution.searchRange(vector1, target1);
    vector<int> solution2 = solution.searchRange(vector2, target2);
    vector<int> solution3 = solution.searchRange(vector3, target3);

    for(auto& x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto& x : solution2) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto& x : solution3) {
        cout << x << ' ';
    }

    return 0;
}