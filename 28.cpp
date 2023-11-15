#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    int strStr(const string& haystack, const string& needle) {
        int firstOccurence = haystack.find(needle);
        return firstOccurence;
    }
};

int main() {
    string haystack1 = "sadbutsad";
    string needle1 = "sad";
    string haystack2 = "leetcode";
    string needle2 = "leeto";

    Solution solution;

    int solution1 = solution.strStr(haystack1, needle1);
    int solution2 = solution.strStr(haystack2, needle2);

    cout << solution1 << '\n';
    cout << solution2 << '\n';


    return 0;
}