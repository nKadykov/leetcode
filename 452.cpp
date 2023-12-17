#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int result = 0;
        sort(points.begin(), points.end());
        vector<int> interval = points[0];
        for(auto x : points) {
            if(x[0] <= interval[1]) {
                interval[1] = min(x[1], interval[1]);
            }
            else {
                result++;
                interval = x;
            }
        }
        result++;
        return result;
    }
};

int main() {
    vector<vector<int>> points1 {
        {10, 16},
        {2, 8},
        {1, 6},
        {7, 12}
    };
    vector<vector<int>> points2 {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8}
    };

    Solution solution;

    int solution1 = solution.findMinArrowShots(points1);
    int solution2 = solution.findMinArrowShots(points2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}