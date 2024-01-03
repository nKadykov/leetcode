#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
    set<int> ind;
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                if(nums1[i] == nums2[j] && ind.count(nums2[j]) == 0) {
                    result.push_back(nums1[i]);
                    ind.insert(nums2[j]);
                }
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

    vector<int> solution1 = solution.intersection(nums11, nums12);
    vector<int> solution2 = solution.intersection(nums21, nums22);

    for(int x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(int x : solution2) {
        cout << x << ' ';
    }

    return 0;
}