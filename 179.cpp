#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    static bool function(int a, int b) {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), function);
        string result = "";
        for(int i = 0; i < nums.size(); i++) {
            result += to_string(nums[i]);
        }
        if(result[0] == '0') {
            return "0";
        }
        return result;
    }
};

int main() {
    vector<int> nums1 {10,2};
    vector<int> nums2 {3,30,34,5,9};

    Solution solution;

    string solution1 = solution.largestNumber(nums1);
    string solution2 = solution.largestNumber(nums2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}