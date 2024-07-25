#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        heap_sort(nums);
        return nums;
    }
private:
    inline void heapify(std::vector<int>& nums, int left, int right) {
        int parent = left;
        int child = (parent<<1) + 1;
        if(child > right)
            return;
        if(child + 1 <= right && nums[child] < nums[child + 1])
            child++;
        if(nums[parent] > nums[child])
            return;
        std::swap(nums[parent], nums[child]);
        heapify(nums, child, right);
    }
    inline void heap_sort(std::vector<int>& nums) {
        const int n = nums.size();
        for(int i = n/2 - 1; i >= 0; --i)
            heapify(nums, i, n - 1);
        for(int i = n - 1; i > 0; --i) {
            std::swap(nums[0], nums[i]);
            heapify(nums, 0, i - 1);
        }
    }
};

int main() {
    std::vector<int> nums1 {5,2,3,1};
    std::vector<int> nums2 {5,1,1,2,0,0};

    Solution solution;

    std::vector<int> solution1 = solution.sortArray(nums1);
    std::vector<int> solution2 = solution.sortArray(nums2);

    for(auto x : solution1) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    for(auto x : solution2) {
        std::cout << x << ' ';
    }

    return 0;
}