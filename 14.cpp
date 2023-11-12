#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string solution = "";
        sort(strs.begin(), strs.end());
        int number = strs.size();  
        string first = strs[0];
        string last = strs[number - 1];
        int flag = 1;
        int i = 0;
        while(flag) {
            if(first[i] == last[i] && first[i]) {
                solution += first[i];
            }
            else {
                flag = 0;
            }
            i++;
        }
        return solution;
    }
};

int main() {
    vector<string> strs1 {"flower","flow","flight"};
    vector<string> strs2 {"dog","racecar","car"};

    Solution sol;

    string sol1 = sol.longestCommonPrefix(strs1);
    cout << sol1 << '\n';
    string sol2 = sol.longestCommonPrefix(strs2);
    cout << sol2 << '\n';
}