#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int numRescueBoats(std::vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int x = 0;
        int right = people.size() - 1;
        for(int i = 0; i <= right; --right) {
            x++;
            if(people[i] <= limit - people[right]) {
                i++;
            }
        }
        return x;
    }
};

int main() {
    std::vector<int> people1 {1, 2};
    std::vector<int> people2 {3, 2, 2, 1};
    std::vector<int> people3 {3, 5, 3, 4};

    int limit1 = 3;
    int limit2 = 3;
    int limit3 = 5;

    Solution solution;

    int solution1 = solution.numRescueBoats(people1, limit1);
    int solution2 = solution.numRescueBoats(people2, limit2);
    int solution3 = solution.numRescueBoats(people3, limit3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0; 
}