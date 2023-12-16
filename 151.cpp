#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int numberDigits = s.size();
        vector<string> resultVector;
        string subString = "";
        for(int i = 0; i < numberDigits; i++){
            if(s[i] == ' '){
                if(subString.size() != 0){
                    resultVector.push_back(subString);
                }
                subString = "";
            }
            else {
                subString += s[i];
            }
        }
        if(subString.size() > 0 && subString[0]!=' ')
            resultVector.push_back(subString);
        string resultString = "";
        int count = resultVector.size();
        for(int i = count - 1; i > 0; i--){
            resultString += resultVector[i];
            resultString += ' ';
        }
        return resultString + resultVector[0];
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