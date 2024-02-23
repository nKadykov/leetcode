#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> degree;
        int m = 0;
        int k = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            if(degree.find(nums[i]) == degree.end()) {
                degree[nums[i]] = vector<int>(2);
            }
            if(++degree[nums[i]][0] == 1) {
                degree[nums[i]][1] = i;
            }
            if(degree[nums[i]][0] > m) {
                m = degree[nums[i]][0];
                k = i - degree[nums[i]][1] + 1;
            }
            else if(degree[nums[i]][0] == m) {
                k = min(k, i - degree[nums[i]][1] + 1);
            }
        }
        return k;
    }
};

int main() {
    vector<int> nums1 {1,2,2,3,1};
    vector<int> nums2 {1,2,2,3,1,4,2};

    Solution solution;

    int solution1 = solution.findShortestSubArray(nums1);
    int solution2 = solution.findShortestSubArray(nums2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}