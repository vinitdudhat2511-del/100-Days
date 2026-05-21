
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1)
            return 1.0;
        if (x == 0)
            return 0.0;
        if (n == -1)
            return 1 / x;

        long binForm = n;
        if (n < 0) {
            x = 1 / x;
            binForm = -binForm;
        }

        double ans = 1;
        while (binForm > 0) {
            if (binForm % 2 == 1) {
                ans *= x;
            }
            x *= x;
            binForm /= 2;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    double x = 2.0;
    int n = 10;
    cout << "myPow(" << x << ", " << n << ") = " << solution.myPow(x, n) << endl;

    x = 2.0; n = -2;
    cout << "myPow(" << x << ", " << n << ") = " << solution.myPow(x, n) << endl;

    x = 0.0; n = 5;
    cout << "myPow(" << x << ", " << n << ") = " << solution.myPow(x, n) << endl;

    x = 1.0; n = 1000;
    cout << "myPow(" << x << ", " << n << ") = " << solution.myPow(x, n) << endl;

    return 0;
}