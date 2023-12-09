#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> result;
        for(int i = 0; i < strs.size(); i++) {
            string answer = strs[i];
            sort(answer.begin(), answer.end());
            map[answer].push_back(strs[i]);
        }
        for(auto x : map) {
            result.push_back(x.second);
        }
        return result;
    }
};

int main() {
    vector<string> strs1 {"eat","tea","tan","ate","nat","bat"};
    vector<string> strs2 {""};
    vector<string> strs3 {"a"};

    Solution solution;

    vector<vector<string>> solution1 = solution.groupAnagrams(strs1);
    vector<vector<string>> solution2 = solution.groupAnagrams(strs2);
    vector<vector<string>> solution3 = solution.groupAnagrams(strs3);

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