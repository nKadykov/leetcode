#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, 1);
        vector<int> hash(n);
        int length = 0;
        int m = 1;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            hash[i] = i;
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && 1 + v[j] > v[i]) {
                    v[i] = 1 + v[j];
                    hash[i] = j;
                }
            }
            if(v[i] > m) {
                m = v[i];
                length = i;
            }
        }
        vector<int> result(m);
        result[0] = nums[length];
        int k = 1;
        while(hash[length] != length) {
            length = hash[length];
            result[k] = nums[length];
            k++; 
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    vector<int> nums1 {1,2,3};
    vector<int> nums2 {1,2,4,8};

    Solution solution;

    vector<int> solution1 = solution.largestDivisibleSubset(nums1);
    vector<int> solution2 = solution.largestDivisibleSubset(nums2);

    for(auto x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : solution2) {
        cout << x << ' ';
    }

    return 0;
} 