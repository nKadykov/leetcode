#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int index = 0;
        std::vector<int>::iterator iter = arr1.begin();
        for(int i = 0; i < n2; ++i) {
            for(int j = 0; j < n1; ++j) {
                if(arr1[j] == arr2[i]) {
                    std::swap((*iter), arr1[j]);
                    iter++;
                }
            }
        }
        sort(iter, arr1.end());
        return arr1;
    }
};

int main() {
    std::vector<int> arr11 = {2,3,1,3,2,4,6,7,9,2,19};
    std::vector<int> arr12 = {2,1,4,3,9,6};
    std::vector<int> arr21 = {28,6,22,8,44,17};
    std::vector<int> arr22 = {22,28,8,6};

    Solution solution;

    std::vector<int> solution1 = solution.relativeSortArray(arr11, arr12);
    std::vector<int> solution2 = solution.relativeSortArray(arr21, arr22);

    for(auto x : solution1) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    for(auto x : solution2) {
        std::cout << x << ' ';
    }

    return 0;
}