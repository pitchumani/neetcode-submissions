class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        int mprofit = 0;
        for (int i=1; i < sz; ++i) {
            auto it = std::min_element(prices.begin(), prices.begin()+i);
            int profit = prices[i] - *it;
            if (profit > mprofit) mprofit = profit;
        }
        return mprofit;
    }
};
