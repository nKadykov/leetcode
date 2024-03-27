#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map;
        vector<string> result;
        int n1 = list1.size();
        int n2 = list2.size();
        for(int i = 0; i < n2; i++) {
            map[list2[i]] = i;
        }
        int minIndexSum = n1 + n2;
        for(int i = 0; i < n1; i++) {
            string s = list1[i];
            if(map.count(s)) {
                int indexSum = i + map[s];
                if(minIndexSum > indexSum) {
                    result.clear();
                    minIndexSum = indexSum;
                    result.push_back(s);
                }
                else if(minIndexSum == indexSum) {
                    result.push_back(s);
                }
            }
        }
        return result;
    }
};

int main() {
    vector<string> list11 = {"Shogun","Tapioca Express","Burger King","KFC"};
    vector<string> list12 = {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};
    vector<string> list21 = {"Shogun","Tapioca Express","Burger King","KFC"};
    vector<string> list22 = {"KFC","Shogun","Burger King"};
    vector<string> list31 = {"happy","sad","good"};
    vector<string> list32 = {"sad","happy","good"};

    Solution solution;

    vector<string> solution1 = solution.findRestaurant(list11, list12);
    vector<string> solution2 = solution.findRestaurant(list21, list22);
    vector<string> solution3 = solution.findRestaurant(list31, list32);

    for(auto &x : solution1) {
        cout << x << ' ';
    }
    cout << endl;
    for(auto &x : solution2) {
        cout << x << ' ';
    }
    cout << endl;
    for(auto &x : solution3) {
        cout << x << ' ';
    }

    return 0;
}