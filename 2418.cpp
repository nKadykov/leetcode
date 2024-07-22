#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> sortPeople(std::vector<std::string>& names, std::vector<int>& heights) {
        int n = names.size();
        std::unordered_map<int, std::string> mapping;
        for(int i = 0; i < n; ++i) {
            mapping[heights[i]] = names[i];
        }
        std::sort(heights.rbegin(), heights.rend());
        for(int i = 0; i < n; ++i) {
            names[i] = mapping[heights[i]];
        }
        return names;
    }
};

int main() {
    std::vector<std::string> names1 {"Mary", "John", "Emma"};
    std::vector<int> heights1 {180, 165, 170};
    std::vector<std::string> names2 {"Alice", "Bob", "Bob"};
    std::vector<int> heights2 {155, 185, 150};

    Solution solution;

    std::vector<std::string> solution1 = solution.sortPeople(names1, heights1);
    std::vector<std::string> solution2 = solution.sortPeople(names2, heights2);

    for(auto& x : solution1) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    for(auto& x : solution2) {
        std::cout << x << ' ';
    }

    return 0;
}