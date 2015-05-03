/** First time. 5/2/2015
 */

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k %= n;
        int temp[k];
        for (int i = n-1; i >= 0; --i) {
            if (i >= n-k) {
                temp[i-n+k] = nums[i];
            }
            else {
                nums[i+k] = nums[i];
            }
        }
        for (int i = 0; i < k; ++i) {
            nums[i] = temp[i];
        }
    }
};