#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    int binarySearch(vector<vector<int>>& pairs, int i) {
        int n = pairs.size();
        int start = i + 1, end = n - 1, result = n;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(pairs[mid][0] > pairs[i][1]) {
                result = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return result;
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<int> dp(n + 1, 0);
        dp[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--) {
            int next = dp[i + 1];
            int nextind = binarySearch(pairs, i);
            int cur = 1 + dp[nextind];
            dp[i] = max(next, cur);
        }
        return dp[0];
    }
};

int main() {
    vector<vector<int>> pairs1 {
        {1, 2},
        {2, 3},
        {3, 4}
    };
    vector<vector<int>> pairs2 {
        {1, 2},
        {7, 8},
        {4, 5}
    };

    Solution solution;

    int solution1 = solution.findLongestChain(pairs1);
    int solution2 = solution.findLongestChain(pairs2);

    cout << solution1 << endl;
    cout << solution2;

    return 0;
}