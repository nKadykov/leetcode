#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        if(s.size() != t.size())
            return false;
        std::unordered_map<char, char> map1;
        std::unordered_map<char, bool> map2;
        for(int i = 0; i < s.size(); ++i) {
            char result1 = s[i];
            char result2 = t[i];
            if(map1.find(result1) != map1.end()) {
                auto it = map1.find(result1);
                if(it->second != result2)
                    return false;
            } else {
                if(map2.find(result2) != map2.end())
                    return false;
                else {
                    map1.insert({result1, result2});
                    map2.insert({result2, true});
                }
            }
        }
        return true;
    }
};

int main() {
    std::string s1 = "egg";
    std::string t1 = "add";
    std::string s2 = "foo";
    std::string t2 = "bar";
    std::string s3 = "paper";
    std::string t3 = "title";

    Solution solution;

    bool solution1 = solution.isIsomorphic(s1, t1);
    bool solution2 = solution.isIsomorphic(s2, t2);
    bool solution3 = solution.isIsomorphic(s3, t3);

    std::cout << std::boolalpha << solution1 << '\n';
    std::cout << solution2 << '\n';
    std::cout << solution3 << '\n';

    return 0;
}