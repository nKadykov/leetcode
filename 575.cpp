#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int distributeCandies(std::vector<int>& candy_type) 
    {
        int n = candy_type.size();
        std::sort(candy_type.begin(), candy_type.end());
        int result = 1;
        for(int i = 0; i < n - 1; ++i)
        {
            if(candy_type[i] != candy_type[i + 1])
            {
                result++;
            }
        }
        int check = n / 2;
        if(result > check)
        {
            result = check;
        }
        return result;
    }
};

int main()
{
    std::vector<int> candy_type1 = {1,1,2,2,3,3};
    std::vector<int> candy_type2 = {1,1,2,3};
    std::vector<int> candy_type3 = {6,6,6,6};

    Solution solution;

    int solution1 = solution.distributeCandies(candy_type1);
    int solution2 = solution.distributeCandies(candy_type2);
    int solution3 = solution.distributeCandies(candy_type3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;
    
    return 0;
}