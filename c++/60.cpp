/**
 * First time. 4/2/2015
 * 
 * Generating all permutations up to the kth has 
 * worst case time complexity of O(n!).
 * This solution determines one digit at a time, 
 * and has a time complexity of O(n).
 */

class Solution {
public:
    string getPermutation(int n, int k) {
        int i = 0;
        string result;
        vector<int> num;
        int factorial = 1;
        
        for (i = 1; i <= n; ++i) {
            num.push_back(i);
        }
        for (i = 2; i <= n; ++i) {
            factorial *= i;
        }
        
        int r = k-1;
        i = n;
        while (i > 0) {
            factorial /= i;
            result += ('0' + num[r / factorial]);
            num.erase(num.begin() + r/factorial);
            r %= factorial;
            --i;
        }
        return result;
    }
};