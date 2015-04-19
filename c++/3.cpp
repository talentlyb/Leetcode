/** First time. 4/19/2015
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int len = 0;
        int start = 0;
	    int maxLen = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (hash.find(s[i]) != hash.end() && hash[s[i]] >= start) {
    			if (i == hash[s[i]]+1) {
    				start = i;
    			}
    			else {
    				start = hash[s[hash[s[i]]+1]];
    			}
    			len = i - start;
            }
            hash[s[i]] = i;
            ++len;
    		if (len > maxLen) {
    			maxLen = len;
    		}
        }
        return maxLen;
    }
};