/** First time. 4/27/2015
 * 
 * Dynamic programming
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = p.length();
        int n = s.length();
		vector<bool> temp (n+1, false);
        vector<vector<bool>> table (m+1, temp);
        
        table[0][0] = true;
        for (int i = 2; i <= m; ++i) {
            if (p[i-1] == '*' && table[i-2][0]) {
                table[i][0] = true;
            }
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
				if (table[i-1][j-1]) {
					if (p[i-1] == '.' || p[i-1] == s[j-1]) {
						table[i][j] = true;
					}
					else if (p[i-1] == '*' && (p[i-2] == '.' || p[i-2] == s[j-1])) {
						table[i][j] = true;
					}
				}
                if (table[i-1][j]) {
					if (p[i-1] == '*') {
						table[i][j] = true;
					}
					else if (table[i-2][j] && p[i-1] == s[j-1] && p[i-2] == '*') {
						table[i][j] = true;
					}
                }
                if (i >= 2 && table[i-2][j]) {
					if (p[i-1] == '*') {
						table[i][j] = true;
					}
				}
				if (table[i][j-1]) {
					if (p[i-1] == '*' && (p[i-2] == '.' || p[i-2] == s[j-1])) {
						table[i][j] = true;
					}
				}
            }
        }
        return table[m][n];
    }
};