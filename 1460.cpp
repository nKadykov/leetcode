#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool canBeEqual(std::vector<int>& target, std::vector<int>& arr) {
        std::unordered_map<int, int> target_map;
        std::unordered_map<int, int> arr_map;
        int target_number = target.size();
        int arr_number = arr.size();
        if(target_number != arr_number) {
            return false;
        }
        for(int i = 0; i < target_number; ++i) {
            target_map[target[i]]++;
            arr_map[arr[i]]++;
        }
        for(auto x : target_map) {
            if(arr_map[x.first] != x.second) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::vector<int> target1 = {1,2,3,4};
    std::vector<int> arr1 = {2,4,1,3};
    std::vector<int> target2 = {7};
    std::vector<int> arr2 = {7};
    std::vector<int> target3 = {3,7,9};
    std::vector<int> arr3 = {3,7,11};

    Solution solution;

    bool solution1 = solution.canBeEqual(target1, arr1);
    bool solution2 = solution.canBeEqual(target2, arr2);
    bool solution3 = solution.canBeEqual(target3, arr3);

    std::cout << std::boolalpha << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}