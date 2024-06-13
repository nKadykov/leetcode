#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {
        int n = seats.size();
        std::sort(seats.begin(), seats.end());
        std::sort(students.begin(), students.end());
        int result = 0;
        for(int i = 0; i < n; ++i) {
            result += abs(seats[i] - students[i]);
        }
        return result;
    }
};

int main() {
    std::vector<int> seats1 = {3, 1, 5};
    std::vector<int> students1 = {2, 7, 4};
    std::vector<int> seats2 = {4, 1, 5, 9};
    std::vector<int> students2 = {1, 3, 2, 6};
    std::vector<int> seats3 = {2, 2, 6, 6};
    std::vector<int> students3 = {1, 3, 2, 6};

    Solution solution;

    int solution1 = solution.minMovesToSeat(seats1, students1);
    int solution2 = solution.minMovesToSeat(seats2, students2);
    int solution3 = solution.minMovesToSeat(seats3, students3);

    std::cout << solution1 << '\n';
    std::cout << solution2 << '\n';
    std::cout << solution3 << '\n';

    return 0;
}