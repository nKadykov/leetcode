#include <iostream>
using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        if(bx2 <= ax1 || bx1 >= ax2 || by1 >= ay2 || ay1 >= by2) {
            return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
        }
        return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - (min(ay2, by2) - max(ay1, by1)) * (min(ax2, bx2) - max(ax1, bx1));
    }
};

int main() {
    int ax11 = -3, ay11 = 0, ax12 = 3, ay12 = 4, bx11 = 0, by11 = -1, bx12 = 9, by12 = 2;
    int ax21 = -2, ay21 = -2, ax22 = 2, ay22 = 2, bx21 = -2, by21 = -2, bx22 = 2, by22 = 2;

    Solution solution;

    int solution1 = solution.computeArea(ax11, ay11, ax12, ay12, bx11, by11, bx12, by12);
    int solution2 = solution.computeArea(ax21, ay21, ax22, ay22, bx21, by21, bx22, by22);
    
    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}