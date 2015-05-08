/** First time. 5/7/2015
 * 
 * Dynamic programming.
 * Keep track of the max positive product, and theh min negative product.
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minNeg = (nums[0] < 0) ? nums[0] : 0;
        int maxPos = (nums[0] > 0) ? nums[0] : 0;
        int result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                maxPos = max(maxPos * nums[i], nums[i]);
                minNeg = min(minNeg, minNeg*nums[i]);
            }
            else if (nums[i] < 0) {
                int temp = maxPos;
                maxPos = minNeg * nums[i];
                minNeg = min(temp * nums[i], nums[i]);
            }
            else {  // nums[i] == 0
                maxPos = 0;
                minNeg = 0;
            }
            if (maxPos == 0) {
                result = max(result, minNeg);
            }
            else if (minNeg == 0) {
                result = max(result, maxPos);
            }
            else {
                result = max(max(result, maxPos), minNeg);
            }
        }
        return result;
    }
};