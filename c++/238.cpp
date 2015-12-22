// First time. 2015/12/22

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i = 0;
        int left = 1;
        int right = 1;
        int n = nums.size();
        vector<int> ret(n, 1);
        for (i = 0; i < n; ++i) {
            // the order of the following statements is important.
            ret[i] *= left;
            left *= nums[i];
            ret[n-1-i] *= right;
            right *= nums[n-1-i];
        }
        return ret;
    }
};
