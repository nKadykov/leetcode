#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int countDuplicates = 1;
        for(int index = 1; index < nums.size(); index++) {
            if(nums[index] != nums[index - 1]) {
                nums[countDuplicates] = nums[index];
                countDuplicates++;
            }
        }
        return countDuplicates;
    }
};

int main() {
    vector<int> vector1 {1, 1, 2};
    vector<int> vector2 {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    Solution solution;

    int dupicates1 = solution.removeDuplicates(vector1);
    cout << dupicates1 << '\n'; 
    int dupicates2 = solution.removeDuplicates(vector2);
    cout << dupicates2 << '\n';
    
    return 0;
}