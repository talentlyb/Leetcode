// First time. 2015/9/26

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ptr1 = 0;
        int ptr2 = 0;
        for (ptr1 = 0; ptr1 < nums.size(); ++ptr1) {
            if (nums[ptr1]) {
                nums[ptr2] = nums[ptr1];
                ++ptr2;
            }
        }
        while (ptr2 < nums.size()) {
            nums[ptr2] = 0;
            ++ptr2;
        }
    }
};
