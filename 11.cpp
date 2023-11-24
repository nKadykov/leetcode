#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(const vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max1 = 0;
        int area = 0;

        while(left < right) {
            area = min(height[left], height[right]) * (right - left);
            max1 = max(max1, area);

            if(height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return max1;
    }
};

int main() {
    vector<int> height1 {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> height2 {1, 1};

    Solution solution;

    int solution1 = solution.maxArea(height1);
    int solution2 = solution.maxArea(height2);

    cout << solution1 << ' ';
    cout << solution2 << ' ';

    return 0;
}