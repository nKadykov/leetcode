#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = nums1.size() - nums2.size() - 1;
        int r = nums2.size() - 1;
        int mid = nums1.size() - 1;
        while (l >= 0 || r >= 0) {
            int lnumb, rnumb;
            if (l >= 0)
                lnumb = nums1[l];
            else
                lnumb = INT_MIN;
            if (r >= 0)
                rnumb = nums2[r];
            else
                rnumb = INT_MIN;
            if (lnumb > rnumb) {
                nums1[mid] = nums1[l];
                l--;
                mid--;
            } 
            else {
                nums1[mid] = nums2[r];
                r--;
                mid--;
            }
        }
    }
};

int main() {
    vector<int> nums11 {1,2,3,0,0,0};
    int m1 = 3;
    vector<int> nums12 {2,5,6};
    int n1 = 3;

    vector<int> nums21 {1};
    int m2 = 1;
    vector<int> nums22 {};
    int n2 = 0;

    vector<int> nums31 {0};
    int m3 = 0;
    vector<int> nums32 {1};
    int n3 = 1;

    Solution solution;

    solution.merge(nums11, m1, nums12, n1);
    solution.merge(nums21, m2, nums22, n2);
    solution.merge(nums31, m3, nums32, n3);

    for(auto x : nums11) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : nums21) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : nums31) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}