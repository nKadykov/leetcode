#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        generate(answer, "", 0, 0, n);
        return answer;
    }
    void generate(vector<string>& answer, string str, int first, int second, int n) {
        if(str.size() == 2 * n) {
            answer.push_back(str);
            return;
        }
        if(first < n) {
            generate(answer, str + '(', first + 1, second, n);
        }
        if(second < first) {
            generate(answer, str + ')', first, second + 1, n);
        }
    }
};

int main() {
    int n1 = 3;
    int n2 = 1;

    Solution solution;

    vector<string> solution1 = solution.generateParenthesis(n1);
    vector<string> solution2 = solution.generateParenthesis(n2);

    for(auto& x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto& x : solution2) {
        cout << x << ' ';
    }

    return 0;
}