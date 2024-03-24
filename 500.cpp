#include <iostream>
#include <vector>
#include <map>
using std::vector;
using std::string;
using std::map;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string s1 = "qwertyuiop";
        string s2 = "asdfghjkl";
        string s3 = "zxcvbnm";
        vector<string> result;
        map<char, int> m;
        for(auto &x : s1) {
            m[x] = 1;
        }
        for(auto &x : s2) {
            m[x] = 2;
        }
        for(auto &x : s3) {
            m[x] = 3;
        }
        for(auto &x : words) {
            int i;
            for(i = 1; i < x.size(); i++) {
                if(m[tolower(x[i])] != m[tolower(x[i - 1])]) {
                    break;
                }
            }
            if(i == x.size())  {
                result.push_back(x);
            }
        }
        return result;
    }
};

int main() {
    using std::cout;
    using std::endl;
    vector<string> w1 {"Hello","Alaska","Dad","Peace"};
    vector<string> w2 {"omk"};
    vector<string> w3 {"adsdf","sfd"};

    Solution solution;

    vector<string> solution1 = solution.findWords(w1);
    vector<string> solution2 = solution.findWords(w2);
    vector<string> solution3 = solution.findWords(w3);

    for(auto &x : solution1) {
        cout << x << ' ';
    }
    cout << endl;
    for(auto &x : solution2) {
        cout << x << ' ';
    }
    cout << endl;
    for(auto &x : solution3) {
        cout << x << ' ';
    }

    return 0;
}