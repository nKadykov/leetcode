#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> v;
    NumArray(vector<int>& nums) {
        v.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            v.push_back(nums[i] + v[i - 1]);
        }
    }
    int sumRange(int left, int right) {
        if(left == 0) {
            return v[right];
        }
        return v[right] - v[left - 1];
    }
};

int main() {
    vector<int> nums {-2,0,3,-5,2,-1};
    int left = 0;
    int right = 2;
    NumArray* obj = new NumArray(nums);
    int param_1 = obj->sumRange(left, right);

    cout << param_1;

    return 0;
}