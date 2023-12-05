#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void solve(int i,int &n,int k,vector<int> &v,vector<int> &tmp,vector<vector<int>> &ans){
        if(k==0){
            ans.push_back(tmp);
            return;
        }if(k<0)return;
        if(i>=n)return;
        for(int j = i; j < n; j++){
            tmp.push_back(v[j]);
            solve(j+1,n,k-v[j],v,tmp,ans);
            while(j+1<n&&v[j]==v[j+1]){
                j++;
            }
            tmp.pop_back();
            
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& v, int k) {
        sort(v.begin(),v.end());
        vector<int> tmp;
        vector<vector<int>> ans;
        int n = v.size();
        solve(0,n,k,v,tmp,ans);
        return ans;
    }
};

int main() {
    vector<int> candidates1 {10,1,2,7,6,1,5};
    int target1 = 8;
    vector<int> candidates2 {2,5,2,1,2};
    int target2 = 5;

    Solution solution;

    vector<vector<int>> solution1 = solution.combinationSum2(candidates1, target1);
    vector<vector<int>> solution2 = solution.combinationSum2(candidates2, target2);

    for(auto x : solution1) {
        for(auto y : x) {
            cout << y << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for(auto x : solution2) {
        for(auto y : x) {
            cout << y << ' ';
        }
        cout << '\n';
    }
    return 0;
}