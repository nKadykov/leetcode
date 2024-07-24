#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>

class Solution {
public:
    std::vector<int> sortJumbled(std::vector<int>& mapping, std::vector<int>& nums) {
        auto translate_integer = [&](int num) -> int {
            std::string digits = std::to_string(num);
            for(char& digit : digits) {
                digit = '0' + mapping[digit - '0'];
            }
            return stoi(digits);
        };
        std::unordered_map<int, int> number_mapping;
        for(int num : nums) {
            if(number_mapping.find(num) == number_mapping.end()) {
                number_mapping[num] = translate_integer(num);
            }
        }
        std::sort(nums.begin(), nums.end(), [&](int a, int b) {
            return number_mapping[a] < number_mapping[b];
        });
        return nums;
    }
};

int main() {
    std::vector<int> mapping1 {8,9,4,0,2,1,3,5,7,6};
    std::vector<int> nums1 {991,338,38};
    std::vector<int> mapping2 {0,1,2,3,4,5,6,7,8,9};
    std::vector<int> nums2 {789,456,123};

    Solution solution;

    std::vector<int> solution1 = solution.sortJumbled(mapping1, nums1);
    std::vector<int> solution2 = solution.sortJumbled(mapping2, nums2);

    for(auto x : solution1) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    for(auto x : solution2) {
        std::cout << x << ' ';
    }

    return 0;
}