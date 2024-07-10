#include <iostream>
#include <vector>
#include <cstring>

class Solution {
public:
    std::string shortestCompletingWord(std::string licensePlate, std::vector<std::string>& words) {
        int license_length = licensePlate.size();
        int words_length = words.size();
        int hash_size = 26;
        int i = 0;
        int* hash_1 = new int[hash_size];
        int* hash_2 = new int[hash_size];
        std::string result = "";
        getHash(licensePlate, hash_1, hash_size);
        for(std::string& word : words) {
            getHash(word, hash_2, hash_size);
            for(i = 0; i < hash_size; ++i) {
                if(hash_2[i] < hash_1[i]) {
                    break;
                }
            }
            if(i == hash_size && (result.empty() || word.size() < result.size())) {
                result = word;
            }
        }
        return result;
    }
private:
    void getHash(std::string& s, int* hash, int hash_size) {
        memset(hash, 0, sizeof(int) * hash_size);
        for(char c : s) {
            if(isLetter(c)) {
                ++hash[toLow(c) - 'a'];
            }
        }
    }
    bool isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    char toLow(char c) {
        if(c >= 'A' && c <= 'Z') {
            c += 'a' - 'A';
        }
        return c;
    }
};

int main() {
    std::string license_plate1 = "1s3 PSt";
    std::vector<std::string> words1 = {"step","steps","stripe","stepple"};
    std::string license_plate2 = "1s3 456";
    std::vector<std::string> words2 = {"looks","pest","stew","show"};

    Solution solution;

    std::string solution1 = solution.shortestCompletingWord(license_plate1, words1);
    std::string solution2 = solution.shortestCompletingWord(license_plate2, words2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}