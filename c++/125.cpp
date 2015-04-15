/** First time. 4/14/2015
 */

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        
        int l = 0;
        int r = s.length()-1;
        while (l < r) {
            while (l < s.length() && (s[l] < '0' || s[l] > '9' && s[l] < 'A' || s[l] > 'Z' && s[l] < 'a' || s[l] > 'z')) {
                ++l;
            }
            if (l == s.length()) {
                return true;
            }
            while (r >= 0 && (s[r] < '0' || s[r] > '9' && s[r] < 'A' || s[r] > 'Z' && s[r] < 'a' || s[r] > 'z')) {
                --r;
            }
            if (r == 0) {
                return true;
            }
            if (s[l] >= 'A' && s[l] <= 'Z') {
                if (s[l] != s[r] && s[l] != (s[r] - 32)) {
                    return false;
                }
            }
            else if (s[l] >= 'a' && s[l] <= 'z') {
                if (s[l] != s[r] && s[l] != (s[r] + 32)) {
                    return false;
                }
            }
            else if (s[l] != s[r]) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
};