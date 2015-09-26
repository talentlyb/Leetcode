// First time. 2015/9/26

class Solution {
public:
    int addDigits(int num) {
        return (num == 0) ? 0 : (num - 1) % 9 + 1;
    }
};
