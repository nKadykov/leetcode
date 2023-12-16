#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        string substring = "";
        s += " ";
        for(auto x : s) {
            if(x != ' ') {
                substring += x;
            }
            else {
                result = substring  + (substring.size() < 1 || result.size() < 1 ? "" : " ") + result;
                substring = "";
            }
        }
        return result;
    }
};

int main() {
    string string1 = "the sky is blue";
    string string2 = "  hello world  ";
    string string3 = "a good   example";
    string string4 = "Je suis tres content";
    string string5 = " asdasd df f";

    Solution solution;

    string solution1 = solution.reverseWords(string1);
    string solution2 = solution.reverseWords(string2);
    string solution3 = solution.reverseWords(string3);
    string solution4 = solution.reverseWords(string4);
    string solution5 = solution.reverseWords(string5);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3 << '\n';
    cout << solution4 << '\n';
    cout << solution5 << '\n';

    return 0;
}