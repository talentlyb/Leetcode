/** First time. 5.2.2015
 */

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        vector<bool> table (n+1, false);
        int sum = 1;
        int upper = sqrt(n);
        for (int i = 3; i < n; i += 2) {
            if (!table[i]) {
                ++sum;
                if (i > upper) {
                    continue;
                }
                for (int j = i * i; j < n; j += i) {
                    table[j] = true;
                }
            }
        }
        return sum;
    }
};