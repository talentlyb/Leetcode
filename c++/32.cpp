/** First time. 4/26/2015
 * 
 * Stack. Store the indices of unmatched parentheses.
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> index;
        int maxLen = 0;
        int len = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (index.empty()) {
                index.push_back(i);
            }
            else {
                if (s[index.back()] == '(' && s[i] == ')') {
                    index.pop_back();
                }
                else {
                    index.push_back(i);
                }
            }
        }
        
        if (index.empty()) {
            return s.length();
        }
        for (int i = 0; i < index.size() - 1; ++i) {
            len = index[i+1] - index[i] - 1;
            if (len > maxLen) {
                maxLen = len;
            }
        }
        int temp1 = index[0];
		int temp2 = s.length()-1-index[index.size()-1];
		maxLen = max(max(temp1, temp2), maxLen);
		
        return maxLen;
    }
};