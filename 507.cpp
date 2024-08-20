#include <iostream>

class Solution {
public:
    bool checkPerfectNumber(int n)
    {
        long long int sum = 0;
        if(n == 1) 
            return false;
        for(int i = 1; i * i <= n ; i++)
        {
            if(n % i == 0)
            {
                sum += i;
                if(n / i != i && n / i != n)
                    sum += n / i;
            }
        }
        return sum == n;
    }
};

int main()
{
    int num1 = 28;
    int num2 = 7;

    Solution solution;

    bool solution1 = solution.checkPerfectNumber(num1);
    bool solution2 = solution.checkPerfectNumber(num2);

    std::cout << std::boolalpha;
    
    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}