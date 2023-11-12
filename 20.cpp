#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

class Solution  {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char& c : s) {
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                if(st.empty() || (c == ')' && st.top() != '(') || (c == '}' && st.top() != '{') || (c == ']' && st.top() != '[')) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "(]";
    string s4 = "{[]}";

    Solution sol;

    bool sol1 = sol.isValid(s1);
    cout << sol1 << '\n';
    bool sol2 = sol.isValid(s2);
    cout << sol2 << '\n';    
    bool sol3 = sol.isValid(s3);
    cout << sol3 << '\n';
    bool sol4 = sol.isValid(s4);
    cout << sol4 << '\n';

    return 0;
}