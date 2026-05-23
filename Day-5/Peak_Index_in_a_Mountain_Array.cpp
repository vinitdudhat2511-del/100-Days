#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int st = 1;
        int end = arr.size() - 2;

        while (st <= end) {

            int mid = st + (end - st) / 2;

            // Peak element found
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid;
            }

            // Increasing slope
            else if (arr[mid - 1] < arr[mid]) {
                st = mid + 1;
            }

            // Decreasing slope
            else {
                end = mid - 1;
            }
        }

        return -1;
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    cout << obj.peakIndexInMountainArray(arr);

    return 0;
}