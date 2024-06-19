#include <iostream>
#include <vector>

class Solution {
public:
    int minDays(std::vector<int>& bloom_day, int m, int k) {
        if((long long)m * k > bloom_day.size()) {
            return -1;
        }
        int low = 1;
        int high = 1e9;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(canMakeBouquets(bloom_day, m, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
private:
    bool canMakeBouquets(std::vector<int>& bloom_day, int m, int k, int day) {
        int total = 0;
        for(int i = 0; i < bloom_day.size(); ++i) {
            int count = 0;
            while (i < bloom_day.size() && count < k && bloom_day[i] <= day) {
                count++;
                i++;
            }
            if(count == k) {
                total++;
                i--;
            }
            if(total >= m) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    std::vector<int> bloom_day1 {1,10,3,10,2};
    int m1 = 3;
    int k1 = 1;
    std::vector<int> bloom_day2 {1,10,3,10,2};
    int m2 = 3;
    int k2 = 2;
    std::vector<int> bloom_day3 {7,7,7,7,12,7,7};
    int m3 = 2;
    int k3 = 3;

    Solution solution;

    int solution1 = solution.minDays(bloom_day1, m1, k1);
    int solution2 = solution.minDays(bloom_day2, m2, k2);
    int solution3 = solution.minDays(bloom_day3, m3, k3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}