#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int lp = 0, rp = height.size() - 1;
        while (lp < rp) {
            int w = rp - lp;
            int ht = min(height[lp], height[rp]);
            int area = w * ht;
            maxWater = max(area, maxWater);
            height[lp] < height[rp] ? lp++ : rp--;
        }
        return maxWater;
    }
};

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution solution;
    cout << "Max area: " << solution.maxArea(height) << endl;
    return 0;
}