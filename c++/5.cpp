/** First time. 4/26/2015
 * 
 * Dynamic programming
 */

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n ==0) {
            return "";
        }
        
        bool table[1000][1000] = {false};
        int maxBegin = 0;
        int maxLen = 1;
        for (int i = 0; i < n; ++i) {
            table[i][i] = true;
        }
        for (int i = 0; i < n-1; ++i) {
            if (s[i] == s[i+1]) {
                table[i][i+1] = true;
                maxBegin = i;
                maxLen = 2;
            }
        }
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i <= n-len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && table[i+1][j-1]) {
                    table[i][j] = true;
                    maxBegin = i;
                    maxLen = len;
                }
            }
        }
        return s.substr(maxBegin, maxLen);
    }
};