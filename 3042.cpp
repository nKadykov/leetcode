#include <iostream>
#include <vector>

class Solution {
public:
    int countPrefixSuffixPairs(std::vector<std::string>& words) 
    {
        int count = 0;
        int n = words.size();
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                if(check(words[i], words[j]))
                    count++;
            }
        }
        return count;
    }
private:
    bool check(std::string &a, std::string  &b)
    {
        int n1 = a.length();
        int n2 = b.length();
        if(n2 < n1)
            return false;
        std::string x = b.substr(0, n1);
        std::string y = b.substr(n2 - n1);
        return a == x && a == y;
    }
};

int main()
{
    std::vector<std::string> words1 = {"a","aba","ababa","aa"};
    std::vector<std::string> words2 = {"pa","papa","ma","mama"};
    std::vector<std::string> words3 = {"abab","ab"};

    Solution solution;

    int solution1 = solution.countPrefixSuffixPairs(words1);
    int solution2 = solution.countPrefixSuffixPairs(words2);
    int solution3 = solution.countPrefixSuffixPairs(words3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}