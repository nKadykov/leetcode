#include <iostream>
#include <vector>

class Solution {
public:
    int countTriplets(std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> prefix(n + 1, 0);
        for(int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        int count = 0;
        for(int i = 0; i < n; ++i) {
            for(int k = i + 1; k < n; ++k) {
                if(prefix[i] == prefix[k + 1]) {
                    count += (k - i);
                }
            }
        }
        return count;
    }
};

int main() {
    std::vector<int> arr1 {2, 3, 1, 6, 7};
    std::vector<int> arr2 {1, 1, 1, 1, 1};

    Solution solution;

    int solution1 = solution.countTriplets(arr1);
    int solution2 = solution.countTriplets(arr2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}