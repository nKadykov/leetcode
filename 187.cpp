#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> str;
        if(s.size() <= 10) {
            return str;
        }
        unordered_map<string, int> mp;
        for(int i = 0; i <= s.size() - 10; i++) {
            if(mp[s.substr(i, 10)]++ == 1) {
                str.push_back(s.substr(i, 10));
            }
        }
        return str;
    }
};

int main() {
    string s1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    string s2 = "AAAAAAAAAAAAA";

    Solution solution;

    vector<string> solution1 = solution.findRepeatedDnaSequences(s1);
    vector<string> solution2 = solution.findRepeatedDnaSequences(s2);

    for(auto x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : solution2) {
        cout << x << ' ';
    }

    return 0;
}

