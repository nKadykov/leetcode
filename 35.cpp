#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, const int& target) {
        int index = 0;
        int number = nums.size();
        if(nums[0] >= target) {
            return 0;
        }
        for(int i = 0; i < number - 1; i++) {
            if(nums[i] == target) {
                index = i;
                return index;
            }
            else {
                if((nums[i] < target) && (nums[i + 1] > target))
                    index = i+1;
            }
        }
        if(target == nums[number - 1]) {
            return (nums.size() - 1);
        }
        else if(target > nums[number - 1]) {
            return number;
        }
        return index;
    }
};

int main() {
    vector<int> vector1 {1, 3, 5, 6};
    int target1 = 5;
    vector<int> vector2 {1, 3, 5, 6};
    int target2 = 2;
    vector<int> vector3 {1, 3, 5, 6};
    int target3 = 7;

    Solution solution;

    int solution1 = solution.searchInsert(vector1, target1);
    int solution2 = solution.searchInsert(vector2, target2);
    int solution3 = solution.searchInsert(vector3, target3);

    cout << solution1 << '\n';    
    cout << solution2 << '\n';
    cout << solution3 << '\n';

    return 0;
}