/** First time. 4/28/2015
 * 
 * Two passes.
 */

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> number (ratings.size(), 1);
        int result = 0;
        for (int i = 1; i < number.size(); ++i) {
            if (ratings[i-1] < ratings[i]) {
                number[i] = number[i-1] + 1;
            }
        }
		for (int i = number.size()-1; i > 0; --i) {
			if (ratings[i-1] > ratings[i]) {
				number[i-1] = max(number[i-1], number[i]+1);
			}
		}
        
        for (int i = 0; i < number.size(); ++i) {
            result += number[i];
        }
        
        return result;
    }
};