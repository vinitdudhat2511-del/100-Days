#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 0, ans = 0;
        for (int val : nums) {
            if (vote == 0) {
                ans = val;
            }
            if (ans == val) {
                vote++;
            } else {
                vote--;
            }
        }

        int count = 0;
        for (int num : nums) {
            if (ans == num) count++;
        }

        return (count > (nums.size() / 2) ? ans : -1);
    }
};

int main() {
    vector<int> nums = {3, 2, 3};
    Solution solution;

    int result = solution.majorityElement(nums);
    if (result != -1) {
        cout << "Majority element: " << result << endl;
    } else {
        cout << "No majority element found" << endl;
    }

    return 0;
}