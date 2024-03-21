#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> st;
        int n = nums2.size();
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums2[st.top()] <= nums2[i]) {
                st.pop();
            }
            if(!st.empty()) {
                m[nums2[i]] = nums2[st.top()];
            }
            else {
                m[nums2[i]] = -1;
            }
            st.push(i);
        }
        for(auto &x : nums1) {
            x = m[x];
        }
        return nums1;
    }
};

int main() {
    vector<int> nums11 {4, 1, 2};
    vector<int> nums12 {1, 3, 4, 2};
    vector<int> nums21 {2, 4};
    vector<int> nums22 {1, 2, 3, 4};

    Solution solution;

    vector<int> solution1 = solution.nextGreaterElement(nums11, nums12);
    vector<int> solution2 = solution.nextGreaterElement(nums21, nums22);

    for(auto &x : solution1) {
        cout << x << ' ';
    }
    cout << endl;
    for(auto &x : solution2) {
        cout << x << ' ';
    }

    return 0;
}