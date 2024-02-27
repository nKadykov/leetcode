#include <iostream>
using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(isupper(s[i])) {
                s[i] = tolower(s[i]);
            }
        }
        return s;
    }
};

int main() {
    string s1 = "Hello";
    string s2 = "here";
    string s3 = "LOVELY";

    Solution solution;

    string solution1 = solution.toLowerCase(s1);
    string solution2 = solution.toLowerCase(s2);
    string solution3 = solution.toLowerCase(s3);

    cout << solution1 << endl;
    cout << solution2 << endl;
    cout << solution3;

    return 0;
}