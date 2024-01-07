#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int n = intervals.size();
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] < end) {
                count++;
                end = min(end, intervals[i][1]);
            }
            else {
                end = intervals[i][1];
                start = intervals[i][0];
            }
        }
        return count;
    }
};

int main() {
    vector<vector<int>> intervals1 {
        {1,2},
        {2,3},
        {3,4},
        {1,3}
    };
    vector<vector<int>> intervals2 {
        {1,2},
        {1,2},
        {1,2}
    };
    vector<vector<int>> intervals3 {
        {1,2},
        {2,3}
    };

    Solution solution;

    int solution1 = solution.eraseOverlapIntervals(intervals1);
    int solution2 = solution.eraseOverlapIntervals(intervals2);
    int solution3 = solution.eraseOverlapIntervals(intervals3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;
}