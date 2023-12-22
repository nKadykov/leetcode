#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int curr = 0;
        char sign = '+';
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])) {
                curr = 10 * curr + int(s[i] - '0');
            }
            if(!isdigit(s[i]) && s[i] != ' ' || i == s.size() - 1) {
                if(sign == '+') {
                    st.push(curr);
                }
                else if(sign == '-') {
                    st.push(-curr);
                }
                else {
                    int num;
                    if(sign == '*'){
                        num = st.top() * curr;
                    }
                    else {
                        num = st.top() / curr;
                    }
                    st.pop();
                    st.push(num);
                }
                sign = s[i];
                curr = 0; 
            }
            
        }
        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};

int main() {
    string s1 = "3+2*2";
    string s2 = " 3/2 ";
    string s3 = " 3+5 / 2 ";

    Solution solution;

    int solution1 = solution.calculate(s1);
    int solution2 = solution.calculate(s2);
    int solution3 = solution.calculate(s3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}