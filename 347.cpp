#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> numbs;
        for(auto x : nums) {
            numbs[x]++;
        }
        vector<vector<int>> table(nums.size() + 1);
        for(auto& [key, value] : numbs) {
            table[value].push_back(key);
        }
        for(int i = table.size() - 1; i >= 0; i--) {
            for(auto x : table[i]) {
                if(k > 0) {
                    result.push_back(x);
                    k--;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums1 {1,1,1,2,2,3};
    vector<int> nums2 {1};
    int k1 = 2;
    int k2 = 1;

    Solution solution;

    vector<int> solution1 = solution.topKFrequent(nums1, k1);
    vector<int> solution2 = solution.topKFrequent(nums2, k2);

    for(auto x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : solution2) {
        cout << x << ' ';
    }
}