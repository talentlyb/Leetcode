// First time. 2015/12/24

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = nums.size() * (nums.size() + 1) / 2;
        int i;
        for (i = 0; i < nums.size(); ++i) {
            sum -= nums[i];
        }
        
        return sum;
    }
};
