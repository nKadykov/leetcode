#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i = 0; i < image.size(); i++) {
            vector<int> flipped;
            for(int j = image[0].size() - 1; j >= 0; j--) {
                int n = abs(image[i][j] - 1);
                flipped.push_back(n);
            }
            image[i] = flipped;
        }
        return image;
    }
};

int main() {
    vector<vector<int>> image1 {
        {1,1,0},
        {1,0,1},
        {0,0,0}
    };
    vector<vector<int>> image2 {
        {1,1,0,0},
        {1,0,0,1},
        {0,1,1,1},
        {1,0,1,0}
    };

    Solution solution;

    vector<vector<int>> solution1 = solution.flipAndInvertImage(image1);
    vector<vector<int>> solution2 = solution.flipAndInvertImage(image2);

    for(auto x : solution1) {
        for(auto y : x) {
            cout << y << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for(auto x : solution2) {
        for(auto y : x) {
            cout << y << ' ';
        }
        cout << '\n';
    }

    return 0;
}