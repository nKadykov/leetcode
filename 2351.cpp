#include <iostream>
#include <unordered_map>

class Solution {
public:
    char repeatedCharacter(std::string s) 
    {
        std::unordered_map<char, int> num_map;
        for(int i = 0; i < s.size(); ++i)
        {
            num_map[s[i]]++;
            if(num_map[s[i]] == 2)
            {
                return s[i];
            }
        }
        return s[0];
    }
};

int main()
{
    std::string s1 = "abccbaacz";
    std::string s2 = "abcdd";

    Solution solution;

    char solution1 = solution.repeatedCharacter(s1);
    char solution2 = solution.repeatedCharacter(s2);
    
    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}