#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int first = intervals[0][0];
        int second = intervals[0][1];
        vector<vector<int>> result;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] >= first && intervals[i][0] <= second) {
                second = max(intervals[i][1], second);
            }
            else {
                vector<int> vec;
                vec.push_back(first);
                vec.push_back(second);
                result.push_back(vec);
                first = intervals[i][0];
                second = intervals[i][1];
            }
        }
        vector<int> vec;
        vec.push_back(first);
        vec.push_back(second);
        result.push_back(vec);
        return result;
    }
};

int main() {
    vector<vector<int>> intervals1 {
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };
    vector<vector<int>> intervals2 {
        {1,4},
        {4,5}
    };

    Solution solution;

    vector<vector<int>> solution1 = solution.merge(intervals1);
    vector<vector<int>> solution2 = solution.merge(intervals2);

    for(auto x : solution1) {
        for(auto y : x) {
            cout << y << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for(auto x : solution2) {
        for(auto y : x) {
            cout << y << ' ';
        }
        cout << '\n';
    }

    return 0;
}