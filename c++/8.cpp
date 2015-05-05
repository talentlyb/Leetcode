/** First time. 5/4/2015
 */

class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int result = 0;
        bool sign = true;
        while (str[i] != '\0' && str[i] == ' ') {
            ++i;
        }
        if (str[i] == '\0') {
            return 0;
        }
        
        if (str[i] == '+') {
            sign = true;
            ++i;
        }
        else if (str[i] == '-') {
            sign = false;
            ++i;
        }
        
        while (str[i] >= '0' && str[i] <= '9') {
            if (result > INT_MAX/10 || result == INT_MAX/10 && str[i] > '7') {
                result = INT_MAX;
            }
            else if (result < INT_MIN/10 || result == INT_MIN/10 && str[i] > '8') {
                result = INT_MIN;
            }
            else {
                if (sign) {
                    result = result * 10 + (str[i] - '0');
                }
                else {
                    result = result * 10 - (str[i] - '0');
                }
            }
            ++i;
        }
        
        return result;
    }
};