#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> kthSmallestPrimeFraction(std::vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0;
        double right = 1.0;

        while(left < right) {
            double mid = (left + right) / 2;
            double max = 0.0;
            int total = 0, num_index = 0, d_index = 0;
            int j = 1;

            for(int i = 0; i < n - 1; i++) {
                while(j < n && arr[i] >= mid * arr[j]) {
                    j++;
                }

                total += (n - j);
                if(j == n) {
                    break;
                }
                double fraction = static_cast<double>(arr[i]) / arr[j];
                if(fraction > max) {
                    num_index = i;
                    d_index = j;
                    max = fraction;
                }
            }
            if(total == k) {
                return {arr[num_index], arr[d_index]};
            }
            else if (total > k) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        return {};
    }
};

int main() {
    std::vector<int> arr1 {1, 2, 3, 5};
    int k1 = 3;
    std::vector<int> arr2 {1, 7};
    int k2 = 1;

    Solution solution;

    auto solution1 = solution.kthSmallestPrimeFraction(arr1, k1);
    auto solution2 = solution.kthSmallestPrimeFraction(arr2, k2);

    for(auto x : solution1) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    for(auto x : solution2) {
        std::cout << x << ' ';
    }

    return 0;
}