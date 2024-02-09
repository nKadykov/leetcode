#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++) {
            int n = target - nums[i];
            if(m.count(n) == 1) {
                return {i + 1, m[n] + 1};
            }
        }
        return {};
    }
};

int main() {
    vector<int> numbers1 {2,7,11,15};
    int target1 = 9;
    vector<int> numbers2 {2,3,4};
    int target2 = 6;
    vector<int> numbers3 {-1, 0};
    int target3 = -1;

    Solution solution;

    vector<int> solution1 = solution.twoSum(numbers1, target1);
    vector<int> solution2 = solution.twoSum(numbers2, target2);
    vector<int> solution3 = solution.twoSum(numbers3, target3);

    for(auto x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : solution2) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : solution3) {
        cout << x << ' ';
    }

    return 0;
}