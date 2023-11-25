#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int number = nums.size();
        int minsum = INT_MAX / 10;
        int j, k;
        int sum;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < number; i++) {
            j = i + 1;
            k = number - 1;
            while(j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if(sum == target) {
                    return target;
                }
                else if(sum > target) {
                    k--;
                }
                else {
                    j++;
                }
                if(abs(sum - target) < abs(minsum - target)) {
                    minsum = sum;
                }
            }
        }
        return minsum;
    }
};

int main() {
    vector<int> vector1 {-1, 2, 1, -4};
    vector<int> vector2 {0, 0, 0};

    int target1 = 1;
    int target2 = 1;

    Solution solution;

    int solution1 = solution.threeSumClosest(vector1, target1);
    int solution2 = solution.threeSumClosest(vector2, target2);

    cout << solution1 << '\n';
    cout << solution2 << '\n';

    return 0;
}