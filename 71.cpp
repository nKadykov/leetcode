#include <cstring>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string result = "";
        int period = 0;
        int n = path.size();
        for(int i = 0; i < n; i++) {
            if(path[i] == '/') {
                continue;
            }
            string temp;
            while(i < n && path[i] != '/') {
                temp += path[i];
                i++;
            }
            if(temp == ".") {
                continue;
            }
            else if(temp == "..") {
                if(!st.empty()) {
                    st.pop();
                }
            }
            else {
                st.push(temp);
            }
        }
        while(!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }
        if(result.size() == 0) {
            return "/";
        }
        return result;
    }
};

int main() {
    string path1 = "/home/";
    string path2 = "/../";
    string path3 = "/home//foo/";

    Solution solution;

    string solution1 = solution.simplifyPath(path1);
    string solution2 = solution.simplifyPath(path2);
    string solution3 = solution.simplifyPath(path3);

    cout << solution1;
    cout << '\n';
    cout << solution2;
    cout << '\n';
    cout << solution3;
    cout << '\n';
}