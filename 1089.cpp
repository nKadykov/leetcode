#include <iostream>
#include <vector>

class Solution {
public:
    void duplicateZeros(std::vector<int>& arr) {
        int n = arr.size();
        int prev = 0;
        int temp = 0;
        for(int i = 0; i < n; ++i) {
            if(arr[i] == 0) {
                prev = 0;
                for(int j = i + 1; j < n; ++j) {
                    temp = arr[j];
                    arr[j] = prev;
                    prev = temp;
                }
                i++;
            }
        }
    }
};

int main() {
    std::vector<int> arr1 = {1,0,2,3,0,4,5,0};
    std::vector<int> arr2 = {1,2,3};

    Solution solution;

    solution.duplicateZeros(arr1);
    solution.duplicateZeros(arr2);

    for(auto& x : arr1) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    for(auto& x : arr2) {
        std::cout << x << ' ';
    }

    return 0;
}