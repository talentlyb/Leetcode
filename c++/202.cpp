/** First time. 4/21/2015
 *
 * Hash table.
 */

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        vector<int> digits;
        while (true) {
            if (n == 1) {
                return true;
            }
            if (s.find(n) != s.end()) {
                return false;
            }
            else {
                s.insert(n);
            }
            digits.clear();
            while (n) {
                digits.push_back(n%10);
                n /= 10;
            }
            for (int i = 0; i < digits.size(); ++i) {
                n += digits[i] * digits[i];
            }
        }
    }
};