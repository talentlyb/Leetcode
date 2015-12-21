// First time. 2015/12/21

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // first pass
        int xor_result = 0;
        int i = 0;
        for (i = 0; i < nums.size(); ++i) {
            xor_result ^= nums[i];
        }
        
        // find a set bit in the XOR result, 
        // which can distinguish the two numbers to find.
        int set_bit = 1;
        for (i = 0; i < 32; ++i) {
            if (xor_result & set_bit) {
                break;
            }
            set_bit <<= 1;
        }
        
        // second pass
        vector<int> ret = {0, 0};
        for (i = 0; i < nums.size(); ++i) {
            if (nums[i] & set_bit) {
                ret[0] ^= nums[i];
            }
            else {
                ret[1] ^= nums[i];
            }
        }
        
        return ret;
    }
};
