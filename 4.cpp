#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> vector;
        for(int i = 0; i < n1; i++) {
            vector.push_back(nums1[i]);
        }
        for(int i = 0; i < n2; i++) {
            vector.push_back(nums2[i]);
        }
        sort(vector.begin(), vector.end());
        int number = vector.size();
        float median = 0;
        if(number % 2 == 0) {
            median = ((float)vector[number / 2 - 1] + (float)vector[number / 2]) / 2;
        }
        else {
            median = vector[number / 2];
        }
        return median;
    }
};

int main() {
    vector<int> nums11 {1, 3};
    vector<int> nums12 {2};
    vector<int> nums21 {1, 2};
    vector<int> nums22 {3, 4};

    Solution solution;

    float solution1;
    float solution2;

    solution1 = solution.findMedianSortedArrays(nums11, nums12);
    solution2 = solution.findMedianSortedArrays(nums21, nums22);

    cout << solution1 << '\n';
    cout << solution2 << '\n';

    return 0;
}