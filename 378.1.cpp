#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        priority_queue<int> heap;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                heap.push(matrix[i][j]);
                if(heap.size() > k) {
                    heap.pop();
                }
            }
        }
        return heap.top();
    }
};

int main() {
    vector<vector<int>> matrix1 {
        {1,5,9},
        {10,11,13},
        {12,13,15}
    };
    vector<vector<int>> matrix2 {
        {-5},
    };
    int k1 = 8;
    int k2 = 1;

    Solution solution;

    int solution1 = solution.kthSmallest(matrix1, k1);
    int solution2 = solution.kthSmallest(matrix2, k2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}