/** 
 * First time. 4/7/2015
 * 
 * String manipulation
 */

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) {
            return s;
        }
        int i, j;
        string result;
        for (i = 0; i < nRows; ++i) {
            j = i;
            if (j == 0 || j == nRows-1) {
                while (j < s.length()) {
                    result.push_back(s[j]);
                    j += 2*(nRows-1);
                }
            }
            else {
                while (j < s.length()) {
                    result.push_back(s[j]);
                    j += 2*(nRows-1-i);
                    if (j < s.length()) {
                        result.push_back(s[j]);
                        j += 2*i;
                    }
                }
            }
        }
        return result;
    }
};