/*
First time. 4/1/2015

Dynamic programming.
For each day, calculate the max profit before it 
and after it, and store in two separate vectors.
Then find the max value from the sum of the two 
vectors.
*/


class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int result = 0;
        int i = 0;
        int minPrice = prices.front();
        int maxPrice = prices.back();
        vector<int> mp1 (prices.size(), 0);
		vector<int> mp2 (prices.size(), 0);
        for (i = 1; i < prices.size(); ++i) {
            minPrice = min(minPrice, prices[i]);
            mp1[i] = max(mp1[i-1],prices[i]-minPrice);
        }
        for (i = prices.size()-2; i >= 0; --i) {
            maxPrice = max(maxPrice, prices[i]);
            mp2[i] = max(mp2[i+1],maxPrice-prices[i]);
        }
        for (i = 0; i < prices.size(); ++i) {
            result = max(result, mp1[i] + mp2[i]);
        }
        return result;
    }
};