#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1=="0" or num2=="0") return "0";
        vector<int> num_1,num_2;
        for(int i=num1.size()-1;i>=0;i--) num_1.push_back(num1[i]-'0');
        for(int i=num2.size()-1;i>=0;i--) num_2.push_back(num2[i]-'0');
        return multiplyH(num_1,num_2);
    }

    string multiplyH(vector<int> num1,vector<int> num2){
        
        vector<int> res;
        auto c=0;
        for(int k=0;k<=num1.size()+num2.size()-2;k++){
            auto s=0;
            for(int i=0;i<=k;i++){
                if (i<num1.size() and k-i<num2.size()){
                    s+= num1[i]*num2[k-i];
                }
                
            }
            res.push_back((s+c)%10);
            c=(s+c)/10;
        }
        while (c){
            res.push_back(c%10);
            c=c/10;
        }
        string ress="";
        for (int i=0;i<res.size();i++) ress=to_string(res[i])+ress;
        return ress;
    }
};

int main() {
    string num11 = "2";
    string num12 = "3";
    string num21 = "123";
    string num22 = "456";

    Solution solution;

    string solution1 = solution.multiply(num11, num12);
    string solution2 = solution.multiply(num21, num22);

    cout << solution1 << '\n';
    cout << solution2 << '\n';

    return 0;
}