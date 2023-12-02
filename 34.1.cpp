#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int number = nums.size();
        vector<int> result;
        if(number == 0) {
            return {-1, -1};
        }
        int begin = 0;
        int end = number - 1;
        int first = -1;
        int second = -1;
        int mid = (begin + end) / 2;
        while(begin <= end) {
            if(nums[mid] == target) {
                break;
            }
            if(nums[mid] > target) {
                end = mid - 1;
            }
            else {
                begin = mid + 1;
            }
            mid = (begin + end) / 2;
        }
        if(number == 1) {
            if(nums[0] == target) {
                return {0, 0};
            }
        }
        if(nums[mid] == target) {
            first = mid;
            second = mid;
            if(first > 0) {
                while(nums[first] == nums[first - 1]) {
                    first--;
                    if(first == 0) {
                        break;
                    }
                }
            }
            if(second < (number - 1)) {
                while(nums[second] == nums[second + 1]) {
                    second++;
                    if(second == number - 1) {
                        break;
                    }
                }
            }
        }
        result.push_back(first);
        result.push_back(second);
        return result;
    }
};

int main() {
    vector<int> vector1 {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    vector<int> vector2 {5, 7, 7, 8, 8, 10};
    int target2 = 6;
    vector<int> vector3;
    int target3 = 0;

    Solution solution;

    vector<int> solution1 = solution.searchRange(vector1, target1);
    vector<int> solution2 = solution.searchRange(vector2, target2);
    vector<int> solution3 = solution.searchRange(vector3, target3);

    for(auto& x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto& x : solution2) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto& x : solution3) {
        cout << x << ' ';
    }

    return 0;
}