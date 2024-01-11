#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> result;
        for(auto x : wordDict) {
            result.insert(x);
        }
        vector<int> m(n + 1, 0);
        m[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(m[j]) {
                    if(result.find(s.substr(j, i - j)) != result.end()) {
                        m[i] = 1;
                        break;
                    }
                }
            }
        }
        return m[n];
    }
};

int main() {
    string s1 = "leetcode";
    string s2 = "applepenapple";
    string s3 = "catsandog";
    vector<string> wordDict1 {"leet","code"};
    vector<string> wordDict2 {"apple","pen"};
    vector<string> wordDict3 {"cats","dog","sand","and","cat"};

    Solution solution;

    bool solution1 = solution.wordBreak(s1, wordDict1);
    bool solution2 = solution.wordBreak(s2, wordDict2);
    bool solution3 = solution.wordBreak(s3, wordDict3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}