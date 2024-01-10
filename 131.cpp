#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        helper(s, 0, path, result);
        return result;
    }
    void helper(string s, int index, vector<string>& path, vector<vector<string>>& result) {
        if(index == s.size()) {
            result.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); i++) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                helper(s, i + 1, path, result);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s1 = "aab";
    string s2 = "a";

    Solution solution;

    vector<vector<string>> solution1 = solution.partition(s1);
    vector<vector<string>> solution2 = solution.partition(s2);

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