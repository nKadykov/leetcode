#include <iostream>
#include <vector>

class Solution {
public:
    int minHeightShelves(std::vector<std::vector<int>>& books, int shelf_width) {
        int n = books.size();
        std::vector<int> f(n + 1);
        f[0] = 0;
        for(int i = 1; i <= n; ++i) {
            int width = books[i - 1][0];
            int height = books[i - 1][1];
            f[i] = f[i - 1] + height;
            for(int j = i - 1; j > 0; --j) {
                width += books[j - 1][0];
                if(width > shelf_width)
                    break;
                height = std::max(height, books[j - 1][1]);
                f[i] = std::min(f[i], f[j - 1] + height);
            }
        }
        return f[n];
    }
};

int main() {
    std::vector<std::vector<int>> books1 {{1,1}, {2,3}, {2,3}, {1,1}, {1,1}, {1,1}, {1,2}};
    int shelf_width1 = 4;
    std::vector<std::vector<int>> books2 {{1,3}, {2,4}, {3,2}};
    int shelf_width2 = 6;

    Solution solution;

    int solution1 = solution.minHeightShelves(books1, shelf_width1);
    int solution2 = solution.minHeightShelves(books2, shelf_width2);

    std::cout << solution1 << '\n';
    std::cout << solution2 << '\n';

    return 0;
}