#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapNumbers;
        int secondNumber;
        int number = nums.size();
        for(int i = 0; i < number; i++) {
            secondNumber = target - nums[i];
            if(mapNumbers.count(secondNumber)) {
                return {mapNumbers[secondNumber], i};
            }
            mapNumbers[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    vector<int> nums1 {2, 7, 11, 15};
    vector<int> nums2 {3, 2, 4};
    vector<int> nums3 {3, 3};

    int target1 = 9;
    int target2 = 6;
    int target3 = 6;
    
    Solution sol;

    vector<int> v1 = sol.twoSum(nums1, target1);
    vector<int> v2 = sol.twoSum(nums2, target2);
    vector<int> v3 = sol.twoSum(nums3, target3);

    for(auto& x : v1)
        cout << x << ' ';
    cout << '\n';
    for(auto& x : v2)
        cout << x << ' ';
    cout << '\n';
    for(auto& x : v3)
        cout << x << ' ';
}