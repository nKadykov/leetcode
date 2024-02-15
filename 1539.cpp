#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] <= k) {
                k++;
            }
            else {
                break;
            }
        }
        return k;
    }
};

int main() {
    vector<int> arr1 {2,3,4,7,11};
    int k1 = 5;
    vector<int> arr2 {1,2,3,4};
    int k2 = 2;

    Solution solution;

    int solution1 = solution.findKthPositive(arr1, k1);
    int solution2 = solution.findKthPositive(arr2, k2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}