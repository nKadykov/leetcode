#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::string countOfAtoms(std::string formula) {
        int n = formula.size();
        std::unordered_map<std::string, int> result_counter;
        std::stack<std::unordered_map<std::string, int>> parethesis_stack;
        int current_index = 0;
        while(current_index < n) {
            char current_char  = formula[current_index];
            if(current_char == '(') {
                current_index++;
                parethesis_stack.push(std::unordered_map<std::string, int>());
                continue;
            }
            if(current_char == ')') {
                std::string mult_string = "";
                current_index++;
                while(current_index < n && isdigit(formula[current_index])) {
                    mult_string += formula[current_index];
                    current_index++;
                }
                int mult = mult_string.empty() ? 1 : stoi(mult_string);
                std::unordered_map<std::string, int> last_counter = parethesis_stack.top();
                parethesis_stack.pop();
                std::unordered_map<std::string, int>& target = parethesis_stack.empty() ? result_counter : parethesis_stack.top();
                for(const auto& [elem, counter] : last_counter) {
                    target[elem] += counter * mult;
                }
                continue;
            }
            std::string current_element = "";
            std::string current_counter_string = "";
            std::unordered_map<std::string, int>& target = parethesis_stack.empty() ? result_counter : parethesis_stack.top();
            while(current_index < n && formula[current_index] != '(' && formula[current_index] != ')') {
                if(isalpha(formula[current_index])) {
                    if(isupper(formula[current_index]) && !current_element.empty()) {
                        target[current_element] += current_counter_string.empty() ? 1 : stoi(current_counter_string);
                        current_element = "";
                        current_counter_string = "";
                    }
                    current_element += formula[current_index];
                } else {
                    current_counter_string += formula[current_index];
                }
                current_index++;
            }
            target[current_element] += current_counter_string.empty() ? 1 : stoi(current_counter_string);
        }
        std::vector<std::string> parts;
        for(const auto& [elem, counter] : result_counter) {
            parts.push_back(elem + (counter == 1 ? "" : std::to_string(counter)));
        }
        sort(parts.begin(), parts.end());
        std::string result;
        for(const auto& part : parts) {
            result += part;
        }
        return result;
    }
};

int main() {
    std::string formula1 = "H2O";
    std::string formula2 = "Mg(OH)2";
    std::string formula3 = "K4(ON(SO3)2)2";

    Solution solution;

    std::string solution1 = solution.countOfAtoms(formula1);
    std::string solution2 = solution.countOfAtoms(formula2);
    std::string solution3 = solution.countOfAtoms(formula3);

    std::cout << solution1 << '\n';
    std::cout << solution2 << '\n';
    std::cout << solution3 << '\n';

    return 0;
}