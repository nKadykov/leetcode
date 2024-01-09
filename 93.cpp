#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<string> result;
    void backtrack(string& inputString, string outputString, int index, int count) {
        if(count > 4) {
            return;
        }
        if(count == 4 && index >= inputString.size()) {
            outputString.pop_back();
            result.push_back(outputString);
            return;
        }
        for(int i = 1; i <= 3 && index + i <= inputString.size(); i++) {
            string num = inputString.substr(index, i);
            if(num[0] == '0' && i != 1) {
                break;
            }
            else if(stol(num) <= 255) {
                backtrack(inputString, outputString + inputString.substr(index, i) + ".", index + i, count + 1);
            }
        }
    }
    vector<string> restoreIpAddresses(string inputString) {
        backtrack(inputString, "", 0, 0);
        return result;
    }
};

int main() {
    string inputString1 = "25525511135";
    string inputString2 = "0000";
    string inputString3 = "101023";

    Solution solution;

    vector<string> solution1 = solution.restoreIpAddresses(inputString1);
    vector<string> solution2 = solution.restoreIpAddresses(inputString2);
    vector<string> solution3 = solution.restoreIpAddresses(inputString3);

    for(auto x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : solution2) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : solution3) {
        cout << x << ' ';
    }

    return 0;
}