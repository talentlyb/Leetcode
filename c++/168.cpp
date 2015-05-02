/** First time. 5/2/2015
 */

class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n) {
			char temp = ((n-1)%26) + 'A';
            result = temp + result;
            n  = (n-1)/26;
        }
        return result;
    }
};