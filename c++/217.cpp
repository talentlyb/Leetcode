// First time. 2015/12/24

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int i;
        for (i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) {
                return true;
            }
        }
        return false;
    }
};
