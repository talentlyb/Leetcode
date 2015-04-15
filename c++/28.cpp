/** First time. 4/14/2015
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() > haystack.length()) {
            return -1;
        }
        
        int i = 0;
        int j = 0;
        while (needle.length() + i <= haystack.length()) {
            j = 0;
            while (j < needle.length()) {
                if (needle[j] != haystack[i+j]) {
                    break;
                }
                else {
                    ++j;
                }
            }
            if (j == needle.length()) {
                return i;
            }
            else {
                ++i;
            }
        }
        
        return -1;
    }
};