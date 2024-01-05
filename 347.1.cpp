#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> numbs;
        for(auto x : nums) {
            numbs[x]++;
        }
        auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        };
        vector<pair<int, int>> vect(numbs.begin(), numbs.end());
        sort(vect.begin(), vect.end(), compare);
        for(int i = 0; i < k; i++) {
            result.push_back(vect[i].first);
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