#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int BestBuy = prices[0], MaxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (BestBuy < prices[i]) {
                MaxProfit = max(MaxProfit, prices[i] - BestBuy);
            }
            BestBuy = min(BestBuy, prices[i]);
        }
        return MaxProfit;
    }
};

int main() {
    int n;
    vector<int> prices;
    cout<<"Give size of the Array : "<<endl;
    cin>>n;
    cout<<"Give Array of Stock Prices : "<<endl;
    for(int i=0;i<n;i++){
        int price;
        cin>>price;
        prices.push_back(price);
    }
    Solution solution;
    cout<<"Maximum Profit : "<<solution.maxProfit(prices);
}