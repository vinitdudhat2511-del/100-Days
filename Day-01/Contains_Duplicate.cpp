#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        return s.size() < nums.size();
    }
};

int main() {
    vector<int> nums;
    int n;

    cout<<"Enter No Of elements in the Array ";
    cin>>n;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        nums.push_back(x);
    }
    
    Solution solution;

    bool result = solution.hasDuplicate(nums);
    cout << (result ? "Contains duplicate" : "No duplicates") << endl;

    return 0;
}