#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() < 3) {
            return {};
        }
        if(nums[0] > 0) {
            return {};
        }
        unordered_map<int, int> mapNumbers;
        for(int i = 0; i < nums.size(); i++) {
            mapNumbers[nums[i]] = i;
        }
        vector<vector<int>> answer;
        for(int i = 0; i < nums.size() - 2; i++) {
            if(nums[i] > 0) {
                break;
            }
            for(int j = i + 1; j < nums.size() - 1; j++) {
                int target = -1 * (nums[i] + nums[j]);
                if(mapNumbers.count(target) && mapNumbers.find(target)->second > j) {
                    answer.push_back({nums[1], nums[j], target});
                }
                j = mapNumbers.find(nums[j])->second;
            }
            i = mapNumbers.find(nums[i])->second;
        }
        return answer;
    }
};

int main() {
    vector<int> v1 {-1, 0, 1, 2, -1, -4};
    vector<int> v2 {0, 1, 1};
    vector<int> v3 {0, 0, 0};
    vector<vector<int>> vector1;
    vector<vector<int>> vector2;
    vector<vector<int>> vector3;

    Solution sol;

    vector1 = sol.threeSum(v1);
    for(vector<vector<int> >::iterator it = vector1.begin(); it != vector1.end(); ++it) {
        for(vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
            cout << (*it2) << ' ';
        }
        cout << '\n';
    }
    cout << "\n\n";
    vector2 = sol.threeSum(v2);
    for(vector<vector<int> >::iterator it = vector2.begin(); it != vector2.end(); ++it) {
        for(vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
            cout << (*it2) << ' ';
        }
        cout << "\n";
    }
    cout << "\n\n";
    vector3 = sol.threeSum(v3);
    for(vector<vector<int> >::iterator it = vector3.begin(); it != vector3.end(); ++it) {
        for(vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
            cout << (*it2) << ' ';
        }
        cout << "\n";
    }
    cout << '\n';
    return 0;
}