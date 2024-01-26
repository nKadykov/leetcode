#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(target < letters[letters.size() - 1]) {
            for(int i = 0; i < letters.size(); i++) {
                if(letters[i] > target) {
                    return letters[i];
                }
            }
        }
        return letters[0];
    }
};

int main() {
    vector<char> letters1 {'c', 'f', 'j'};
    char target1 = 'a';
    vector<char> letters2 {'c', 'f', 'j'};
    char target2 = 'c';
    vector<char> letters3 {'x', 'x', 'y', 'y'};
    char target3 = 'z';

    Solution solution;

    char solution1 = solution.nextGreatestLetter(letters1, target1);
    char solution2 = solution.nextGreatestLetter(letters2, target2);
    char solution3 = solution.nextGreatestLetter(letters3, target3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}