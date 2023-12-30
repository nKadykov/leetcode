#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int power(int a, int k) {
        a %= 1337;
        int result = 1;
        for(int i = 0; i < k; i++) {
            result = (result * a) % 1337;
        }
        return result;
    }
public:
    int superPow(int a, vector<int>& b) {
        if(b.size() == 0) {
            return 1;
        }
        int last = b.back();
        b.pop_back();
        return power(superPow(a, b) , 10) * power(a, last) % 1337;
    }
};

int main() {
    int a1 = 2;
    int a2 = 2;
    int a3 = 1;
    vector<int> b1 {3};
    vector<int> b2 {1,0};
    vector<int> b3 {4,3,3,8,5,2};

    Solution solution;

    int solution1 = solution.superPow(a1, b1);
    int solution2 = solution.superPow(a2, b2);
    int solution3 = solution.superPow(a3, b3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}