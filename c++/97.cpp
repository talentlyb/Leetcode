/** First time. 4/28/2015
 * 
 * Dynamic programming
 */

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) {
            return false;
        }
        
        int m = s1.length();
        int n = s2.length();
        bool table[m+1][n+1];
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0 && j == 0) {
                    table[i][j] = true;
                }
                else if (i == 0) {
                    table[i][j] = table[i][j-1] && (s2[j-1] == s3[i+j-1]);
                }
                else if (j == 0) {
                    table[i][j] = table[i-1][j] && (s1[i-1] == s3[i+j-1]);
                }
                else {
                    table[i][j] = (table[i][j-1] && (s2[j-1] == s3[i+j-1])) || (table[i-1][j] && (s1[i-1] == s3[i+j-1]));
                }
            }
        }
        
        return table[m][n];
    }
};