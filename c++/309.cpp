// First time. 2016/1/14
// Dynamic programming with FSM

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int rest = 0;        // the state where you do nothing
        int hold = INT_MIN;  // the state where you just finished buying
        int sold = 0;        // the state where you just finished selling
        int prevSold = 0;    // previous sold value
        
        for (int i = 0; i < prices.size(); ++i) {
            prevSold = sold;
            sold = hold + prices[i];
            hold = max(hold, rest - prices[i]);
            rest = max(rest, prevSold);
        }
        
        return max(rest, sold);
    }
};
