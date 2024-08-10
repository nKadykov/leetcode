#include <iostream>
#include <vector>

class Solution {
public:
    int regionsBySlashes(std::vector<std::string>& grid) {
        int n = grid.size();
        int dots = n + 1;
        parent.resize(dots * dots);
        rank.resize(dots * dots, 1);
        count = 0;
        for(int i = 0; i < parent.size(); ++i) {
            parent[i] = i;
        }
        for(int i = 0; i < dots; ++i) {
            for(int j = 0; j < dots; ++j) {
                if(i == 0 || j == 0 || i == n || j == n) {
                    int cell = i * dots + j;
                    unionSets(0, cell);
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '\\') {
                    int cell1 = i * dots + j;
                    int cell2 = (i + 1) * dots + (j + 1);
                    unionSets(cell1, cell2);
                } else if(grid[i][j] == '/') {
                    int cell1 = (i + 1) * dots + j;
                    int cell2 = i * dots + (j + 1);
                    unionSets(cell1, cell2);
                }
            }
        }
        return count;
    }
private:
    std::vector<int> parent;
    std::vector<int> rank;
    int count;
    void unionSets(int a, int b) {
        int parentA = find(a);
        int parentB = find(b);
        if(parentA == parentB) {
            count++;
        } else {
            if(rank[parentA] > rank[parentB]) {
                parent[parentB] = parentA;
            } else if(rank[parentA] < rank[parentB]) {
                parent[parentA] = parentB;
            } else {
                parent[parentB] = parentA;
                rank[parentA]++;
            }
        }
    }
    int find(int a) {
        if(parent[a] == a) {
            return a;
        }
        return parent[a] = find(parent[a]);
    }
};

int main() {
    std::vector<std::string> grid1 {" /", "/ "};
    std::vector<std::string> grid2 {" /", " "};
    std::vector<std::string> grid3 {"/\\", "\\/"};

    Solution solution;

    int solution1 = solution.regionsBySlashes(grid1);
    int solution2 = solution.regionsBySlashes(grid2);
    int solution3 = solution.regionsBySlashes(grid3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}