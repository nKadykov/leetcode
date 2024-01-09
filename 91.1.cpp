#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string inputString) {
        int numberOfLetters = inputString.size();
        vector<int> arrayOfDecodings(numberOfLetters + 1);
        arrayOfDecodings[numberOfLetters] = 1;
        for(int index = numberOfLetters - 1; index >= 0; index--) {
            if(inputString[index] != '0') {
                arrayOfDecodings[index] = arrayOfDecodings[index + 1];
                if(index < numberOfLetters - 1 && (inputString[index] == '1' || inputString[index] == '2' && inputString[index + 1] < '7')) {
                    arrayOfDecodings[index] += arrayOfDecodings[index + 2];
                }
            }
        }
        return arrayOfDecodings[0];
    }
};

int main() {
    string inputString1 = "12";
    string inputString2 = "226";
    string inputString3 = "06";

    Solution solution;

    int solution1 = solution.numDecodings(inputString1);
    int solution2 = solution.numDecodings(inputString2);
    int solution3 = solution.numDecodings(inputString3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3 << '\n';

    return 0;
}