#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                a += b;
                st.push(a);
            }
            else if(tokens[i] == "-") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                b -= a;
                st.push(b);
            }
            else if(tokens[i] == "*") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                a *= b;
                st.push(a);
            }
            else if(tokens[i] == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                b /= a;
                st.push(b);
            }
            else {
                int a = stoi(tokens[i]);
                st.push(a);
            }
        }
        return(st.top()); 
    }
};

int main() {
    vector<string> tokens1 {"2","1","+","3","*"};
    vector<string> tokens2 {"4","13","5","/","+"};
    vector<string> tokens3 {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    Solution solution;

    int solution1 = solution.evalRPN(tokens1);
    int solution2 = solution.evalRPN(tokens2);
    int solution3 = solution.evalRPN(tokens3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}