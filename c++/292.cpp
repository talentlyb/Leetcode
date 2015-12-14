class Solution {
public:
    bool canWinNim(int n) {
        return ((n & 0x00000003) != 0);     // test if n is a multiply of 4.
    }
};
