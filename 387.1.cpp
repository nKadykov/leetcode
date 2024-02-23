#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }
        for(int i = 0; i < s.size(); i++) {
            if(m[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    string s1 = "leetcode";
    string s2 = "loveleetcode";
    string s3 = "aabb";

    Solution solution;

    int solution1 = solution.firstUniqChar(s1);
    int solution2 = solution.firstUniqChar(s2);
    int solution3 = solution.firstUniqChar(s3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}