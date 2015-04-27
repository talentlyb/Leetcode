/** First time. 4/26/2015
 * 
 * Bit manipulation
 */

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == n) {
            return m;
        }
        int gap  = n - m;
        int msb = 0;
        while (gap) {
            gap >>= 1;
            ++msb;
        }
        int mask = ~((1<<msb)-1);
        return m & n & mask;
    }
};