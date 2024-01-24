#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> numbers;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            numbers[nums[i]]++;
        }
        for(auto x : numbers) {
            if(x.second > 1) {
                return x.first;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums1 {1,3,4,2,2};
    vector<int> nums2 {3,1,3,4,2};

    Solution solution;

    int solution1 = solution.findDuplicate(nums1);
    int solution2 = solution.findDuplicate(nums2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}