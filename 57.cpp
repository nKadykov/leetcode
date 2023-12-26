#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& n) {
        in.push_back(n);
        vector<vector<int>> result = merge(in);
        return result;
    }

    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<vector<int>> result;
        int n = in.size();
        sort(in.begin(), in.end());
        int i = 1;
        int begin = in[0][0];
        int end = in[0][1];
        while(i < n) {
            if(in[i][0] >= begin && in[i][0] <= end) {
                end = max(end, in[i][1]);
                i++;
            }
            else {
                vector<int> v;
                v.push_back(begin);
                v.push_back(end);
                result.push_back(v);
                begin = in[i][0];
                end = in[i][1];
                i++;
            }
        }

        vector<int> v;
        v.push_back(begin);
        v.push_back(end);
        result.push_back(v);

        return result;
    }
};

int main() {
    vector<vector<int>> intervals1 = {
        {1,3},
        {6,9}
    };
    vector<int> newInterval1 = {2,5};
    vector<vector<int>> intervals2 = {
        {1,2},
        {3,5},
        {6,7},
        {8,10},
        {12,16}
    };
    vector<int> newInterval2 = {4,8};

    Solution solution;

    vector<vector<int>> solution1 = solution.insert(intervals1, newInterval1);
    vector<vector<int>> solution2 = solution.insert(intervals2, newInterval2);

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