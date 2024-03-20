#include <iostream>
#include <vector>

class Solution {
public:
    int maximumSum(std::vector<int>& arr) {
        int del = 0;
        int stay = arr[0];
        int result = arr[0];
        for(int i = 1; i < arr.size(); i++) {
            del = std::max(stay, del + arr[i]);
            stay = std::max(stay + arr[i], arr[i]);
            result = std::max(result, std::max(del, stay));
        }
        return result;
    }
};

int main() {
    std::vector<int> arr1 {1, -2, 0, 3};
    std::vector<int> arr2 {1, -2, -2, 3};
    std::vector<int> arr3 {-1, -1, -1, -1};

    Solution solution;

    int solution1 = solution.maximumSum(arr1);
    int solution2 = solution.maximumSum(arr2);
    int solution3 = solution.maximumSum(arr3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}