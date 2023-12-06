#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") {
            return "0";
        }
        vector<int> number1;
        vector<int> number2;
        for(int i = num1.size() - 1; i >= 0; i--) {
            number1.push_back(num1[i] - '0');
        }
        for(int i = num2.size() - 1; i >= 0; i--) {
            number2.push_back(num2[i] - '0');
        }
        return solve(number1, number2);
    }
    
    string solve(vector<int>& n1, vector<int>& n2) {
        vector<int> result;
        int c = 0;
        for(int i = 0; i <= n1.size() + n2.size() - 2; i++) {
            int sum = 0;
            for(int j = 0; j <= i; j++) {
                if(j < n1.size() && i - j < n2.size()) {
                    sum += n1[j] * n2[i - j];
                }
            }
            result.push_back((sum + c) % 10);
            c = (sum + c) / 10;
        }
        while(c) {
            result.push_back(c % 10);
            c = c / 10;
        }
        string str = "";
        for(int i = 0; i < result.size(); i++) {
            str = to_string(result[i]) + str;
        }
        return str;
    }
};

int main() {
    string num11 = "2";
    string num12 = "3";
    string num21 = "123";
    string num22 = "456";

    Solution solution;

    string solution1 = solution.multiply(num11, num12);
    string solution2 = solution.multiply(num21, num22);

    cout << solution1 << '\n';
    cout << solution2 << '\n';

    return 0;
}