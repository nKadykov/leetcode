#include <iostream>
#include <vector>

class Solution {
public:
    int countTime(std::string time) 
    {
        std::vector<int> times;
        if(time[0] == '?')
        {
            if(time[1] != '?' && time[1] - 48 <= 3)
                times.push_back(3);
            else if(time[1] != '?' && time[1] - 48 >= 4)
                times.push_back(2);
            else if(time[1] == '?')
                times.push_back(24);
        }
        if(time[1] == '?')
        {
            if(time[0] != '?' && time[0] - 48 <= 1)
                times.push_back(10);
            else if(time[0] != '?' && time[0] - 48 == 2)
                times.push_back(4);
        }
        if(time[3] == '?')
            times.push_back(6);
        if(time[4] == '?')
            times.push_back(10);
        int result = 1;
        for(auto x : times)
            result *= x;
        return result;
    }
};

int main()
{
    std::string time1 = "?5:00";
    std::string time2 = "0?:0?";
    std::string time3 = "??:??";

    Solution solution;

    int solution1 = solution.countTime(time1);
    int solution2 = solution.countTime(time2);
    int solution3 = solution.countTime(time3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}