/** First time. 4/26/2015
 * 
 * Assume both input numbers are integers.
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        string result (num1.length() + num2.length(), '0');
        int carry = 0;
        int temp = 0;
        for (int i = num1.length()-1; i >= 0; --i) {
            carry = 0;
            for (int j = num2.length()-1; j >= 0; --j) {
                temp = (num1[i]-'0') * (num2[j]-'0') + carry + result[result.length()-1-(num1.length()-1-i)-(num2.length()-1-j)] - '0';
                result[result.length()-1-(num1.length()-1-i)-(num2.length()-1-j)] = (temp%10) + '0';
                carry = temp/10;
            }
            if (carry) {
                result[result.length()-1-(num1.length()-1-i)-num2.length()] = carry + '0';
            }
        }
        while (result.length() > 1 && result[0] == '0') {
            result = result.substr(1, result.length()-1);
        }
        return result;
    }
};