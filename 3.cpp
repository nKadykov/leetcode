#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        unordered_set<char> charSet;
        int left = 0;
        for(int right = 0; right < n; right++) {
            if(charSet.count(s[right]) == 0) {
                charSet.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
                // cout << "count(s[right]) = 0\n";
            }
            else {
                while(charSet.count(s[right])) {
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.insert(s[right]);
                // cout << "cout(s[right])\n";
            }
        }
        return maxLength;
    }
};

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        unordered_set<char> charSet;
        int right = 0, left = 0;
        for(right = 0; right < s.length(); right++) {
            while(charSet.count(s[right])) {
                charSet.erase(s[left]);
            }
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

int main() {
    string s1 = "abcdef", s2 = "bbbbbb", s3 = "pwwkew";
    Solution solution;
    int maxLength = solution.lengthOfLongestSubstring(s1);
    cout << maxLength << '\n';
    maxLength = solution.lengthOfLongestSubstring(s2);
    cout << maxLength << '\n';
    maxLength = solution.lengthOfLongestSubstring(s3);
    cout << maxLength << '\n';

    Solution2 solution2;
    maxLength = solution2.lengthOfLongestSubstring(s1);
    cout << maxLength << '\n';
    maxLength = solution2.lengthOfLongestSubstring(s2);
    cout << maxLength << '\n';
    maxLength = solution2.lengthOfLongestSubstring(s3);
    cout << maxLength << '\n';

    return 0;
}