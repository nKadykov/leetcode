#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        a.erase(set_intersection(a.begin(), a.end(), b.begin(), b.end(), a.begin()), a.end());
        return a;
    }
};

int main() {
    vector<int> nums11 {1,2,2,1};
    vector<int> nums12 {2,2};
    vector<int> nums21 {4,9,5};
    vector<int> nums22 {9,4,9,8,4};

    Solution solution;

    vector<int> solution1 = solution.intersect(nums11, nums12);
    vector<int> solution2 = solution.intersect(nums21, nums22);

    for(auto x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : solution2) {
        cout << x << ' ';
    }

    return 0;
}