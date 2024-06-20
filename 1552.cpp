#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int maxDistance(std::vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int lo = 1;
        int hi = (position.back() - position[0]) / (m - 1);
        int ans = 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canWePlace(position, mid, m)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

private:
    bool canWePlace(const std::vector<int>& arr, int dist, int balls) {
        int countBalls = 1;
        int lastPlaced = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - lastPlaced >= dist) {
                countBalls++;
                lastPlaced = arr[i];
            }
            if (countBalls >= balls) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    std::vector<int> position1 = {1,2,3,4,7};
    int m1 = 3;
    std::vector<int> position2 = {5,4,3,2,1,1000000000};
    int m2 = 2;

    Solution solution;

    int solution1 = solution.maxDistance(position1, m1);
    int solution2 = solution.maxDistance(position2, m2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}