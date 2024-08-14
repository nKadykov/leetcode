#include <iostream>
#include <cstring>
#include <map>
#include <sstream>
#include <vector>

class Solution {
public:
    std::string mostCommonWord(std::string paragraph, std::vector<std::string>& banned) \
    {
        for(auto& ch : paragraph)
        {
            if(!isalpha(ch))
                ch = ' ';
            ch = tolower(ch);
        }
        std::map<std::string, int> mp, band;
        for(auto s : banned)
            band[s]++;
        std::string s, result;
        std::stringstream ss(paragraph);
        while(ss >> s)
            if(band[s] == 0)
                mp[s]++;
        int max_num = INT_MIN;
        for(auto [a, b] : mp)
            if(b > max_num)
            {
                result = a;
                max_num = b;
            }
        return result;
    }
};

int main()
{
    std::string paragraph1 = "Bob hit a ball, the hit BALL flew far after it was hit.";
    std::vector<std::string> banned1 = {"hit"};
    std::string paragraph2 = "a.";
    std::vector<std::string> banned2 = {};

    Solution solution;

    std::string solution1 = solution.mostCommonWord(paragraph1, banned1);
    std::string solution2 = solution.mostCommonWord(paragraph2, banned2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
}