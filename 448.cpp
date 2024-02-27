#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        unordered_map<int, int> m;
        for(auto x : nums) {
            m[x]++;
        }
        for(int i = 1; i <= nums.size(); i++) {
            if(m[i] == 0) {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums1 {4,3,2,7,8,2,3,1};
    vector<int> nums2 {1,1};

    Solution solution;

    vector<int> solution1 = solution.findDisappearedNumbers(nums1);
    vector<int> solution2 = solution.findDisappearedNumbers(nums2);

    for(auto x : solution1) {
        cout << x << ' ';
    }
    cout << endl;
    for(auto x : solution2) {
        cout << x << ' ';
    }

    return 0;
} 