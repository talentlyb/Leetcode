// First time. 2016/1/15

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        
        int mask = 1;
        int bitSum = 0;
        for (int i = 0; i < 32; ++i) {
            if (n & mask) {
                ++bitSum;
            }
            mask <<= 1;
        }
        
        return (bitSum == 1);
    }
};
