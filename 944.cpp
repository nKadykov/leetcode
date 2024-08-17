#include <iostream>
#include <vector>

class Solution {
public:
    int minDeletionSize(std::vector<std::string>& strs) 
    {
        int result = 0;
        for(int i = 0; i < strs[0].size(); i++) 
        {
            for(int j = 1; j < strs.size(); j++) 
            {
                if(strs[j][i] < strs[j - 1][i])
                {
                    result++;
                    break;
                }
            }
        }
        return result;
    }
};

int main()
{
    std::vector<std::string> strs1 {"cba","daf","ghi"};
    std::vector<std::string> strs2 {"a","b"};
    std::vector<std::string> strs3 {"zyx","wvu","tsr"};

    Solution solution;

    int solution1 = solution.minDeletionSize(strs1);
    int solution2 = solution.minDeletionSize(strs2);
    int solution3 = solution.minDeletionSize(strs3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}