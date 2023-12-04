#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void solve(vector<int> candidates, int target, vector<vector<int>>& answer, int currentIndex, int currentSum, vector<int> currentArray) {
        if(currentSum > target) {
            return;
        }
        if(currentSum == target) {
            answer.push_back(currentArray);
            return;
        }
        for(int i = currentIndex; i < candidates.size(); i++) {
            currentSum += candidates[i];
            currentArray.push_back(candidates[i]);
            solve(candidates, target, answer, i, currentSum, currentArray);
            currentArray.pop_back();
            currentSum -= candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> currentArray;
        solve(candidates, target, answer, 0, 0, currentArray);
        return answer;
    }
};

int main() {
    vector<int> candidates1 {2,3,6,7};
    int target1 = 7;
    vector<int> candidates2 {2,3,5};
    int target2 = 8;
    vector<int> candidates3 {2};
    int target3 = 1;

    Solution solution;

    vector<vector<int>> solution1 = solution.combinationSum(candidates1, target1);
    vector<vector<int>> solution2 = solution.combinationSum(candidates2, target2);
    vector<vector<int>> solution3 = solution.combinationSum(candidates3, target3);

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
    cout << '\n';
    for(auto x : solution3) {
        for(auto y : x) {
            cout << y << ' ';
        }
        cout << '\n';
    }
    return 0;
}