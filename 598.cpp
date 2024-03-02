#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int a = m;
        int b = n;
        for(auto i : ops) {
            if(i[0] < a) {
                a = i[0];
            }
            if(i[1] < b) {
                b = i[1];
            }
        }
        return (a * b);
    }
};

int main() {
    int m1 = 3;
    int n1 = 3;
    vector<vector<int>> ops1 {
        {2, 2},
        {3, 3}
    };
    int m2 = 3;
    int n2 = 3;
    vector<vector<int>> ops2 {
        {2, 2},
        {3, 3},
        {3, 3},
        {3, 3},
        {3, 3},
        {2, 2},
        {2, 2}
    };
    int m3 = 3;
    int n3 = 3;
    vector<vector<int>> ops3;

    Solution solution;

    int solution1 = solution.maxCount(m1, n1, ops1);
    int solution2 = solution.maxCount(m2, n2, ops2);
    int solution3 = solution.maxCount(m3, n3, ops3);

    cout << solution1 << endl;
    cout << solution2 << endl;
    cout << solution3;

    return 0;
}