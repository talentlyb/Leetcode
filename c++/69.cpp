/**
 * First time. 4/2/2015
 * 
 * Binary search
 */

class Solution {
public:
    int sqrt(int x) {
        if (x < 0) {
            return -1;
        }
        int begin = 0;
        int end = 46340;
        int mid = begin + ((end-begin) >> 1);
        while (begin <= end) {
            if (mid * mid < x) {
                begin = mid + 1;
            }
            else if (mid * mid > x) {
                end = mid - 1;
            }
            else {
                return mid;
            }
            mid = begin + ((end-begin) >> 1);
        }
        return mid;
    }
};