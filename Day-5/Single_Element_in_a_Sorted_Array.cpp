#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        int st = 0;
        int end = n - 1;

        while (st <= end) {

            int mid = st + (end - st) / 2;

            // Edge cases
            if (mid == 0) {
                return nums[0];
            }

            if (mid == n - 1) {
                return nums[n - 1];
            }

            // Unique element found
            if (nums[mid] != nums[mid - 1] &&
                nums[mid] != nums[mid + 1]) {

                return nums[mid];
            }

            // Even index
            else if (mid % 2 == 0) {

                if (nums[mid] == nums[mid - 1]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            }

            // Odd index
            else {

                if (nums[mid] == nums[mid - 1]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    cout << obj.singleNonDuplicate(nums);

    return 0;
}