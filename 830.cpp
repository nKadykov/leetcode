#include <iostream>
#include <vector>

class Solution 
{
public:
    std::vector<std::vector<int>> largeGroupPositions(std::string s) 
    {
        int begin = 0;
        int end = 0;
        std::vector<std::vector<int>> result;
        for(int i = 0; i < s.size(); ++i) 
        {
            if(s[i] == s[i + 1]) 
            {
                end++;
            } else
            {
                if((end - begin + 1) > 2)
                {
                    std::vector<int> group;
                    group.push_back(begin);
                    group.push_back(end);
                    result.push_back(group);
                }
                begin = i + 1;
                end = i + 1;
            }
        }
        return result;
    }
};

int main() 
{
    std::string s1 = "abbxxxxzzy";
    std::string s2 = "abc";
    std::string s3 = "abcdddeeeeaabbbcd";

    Solution solution;

    std::vector<std::vector<int>> solution1 = solution.largeGroupPositions(s1);
    std::vector<std::vector<int>> solution2 = solution.largeGroupPositions(s2);
    std::vector<std::vector<int>> solution3 = solution.largeGroupPositions(s3);

    for(auto x : solution1) {
        for(int i : x) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    for(auto x : solution2) {
        for(int i : x) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    for(auto x : solution3) {
        for(int i : x) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
    
    return 0;
}