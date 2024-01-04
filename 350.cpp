#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int l1 = nums1.size();
        int l2 = nums2.size();
        int i = 0;
        int j = 0;
        while(i < l1 && j < l2) {
            if(nums1[i] < nums2[j]) {
                i++;
            }
            else if(nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] > nums2[j]) {
                j++;
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums11 {1,2,2,1};
    vector<int> nums12 {2,2};
    vector<int> nums21 {4,9,5};
    vector<int> nums22 {9,4,9,8,4};

    Solution solution;

    vector<int> solution1 = solution.intersect(nums11, nums12);
    vector<int> solution2 = solution.intersect(nums21, nums22);

    for(auto x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : solution2) {
        cout << x << ' ';
    }

    return 0;
}