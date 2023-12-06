#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    void function(const vector<int>& candidates, int& target, int currentIndex, int currentSum, vector<int> currentArray, vector<vector<int>>& result) {
        if(currentSum > target) {
            return;
        }
        if(currentSum == target) {
            result.push_back(currentArray);
            return;
        }
        if(currentIndex > candidates.size()) {
            return;
        }
        for(int i = currentIndex; i < candidates.size(); i++) {
            currentArray.push_back(candidates[i]);
            function(candidates, target, i + 1, currentSum + candidates[i], currentArray, result);
            while(i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
                i++;
            } 
            currentArray.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> currentArray;
        function(candidates, target, 0, 0, currentArray, result);
        return result;
    }
};

int main() {
    vector<int> candidates1 {10,1,2,7,6,1,5};
    int target1 = 8;
    vector<int> candidates2 {2,5,2,1,2};
    int target2 = 5;

    Solution solution;

    vector<vector<int>> solution1 = solution.combinationSum2(candidates1, target1);
    vector<vector<int>> solution2 = solution.combinationSum2(candidates2, target2);

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