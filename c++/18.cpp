/** First time. 4/18/2015
 * 
 * Two pointers
 */

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int i1, i2, i3, i4;
        int n = num.size();
        vector<vector<int>> result;
        if (n < 4) {
            return result;
        }
        
        for (i1 = 0; i1 < n-3; ++i1) {
            if (i1 > 0 && num[i1] == num[i1-1]) {
                continue;
            }
            for (i2 = i1 + 1; i2 < n-2; ++i2) {
                if (i2 > i1 + 1 && num[i2] == num[i2-1]) {
                    continue;
                }
                int numToFind = target - num[i1] - num[i2];
                i3 = i2 + 1;
                i4 = n-1;
                while (i3 < i4) {
                    if (num[i3] + num[i4] < numToFind) {
                        ++i3;
                    }
                    else if (num[i3] + num[i4] > numToFind) {
                        --i4;
                    }
                    else {
                        vector<int> temp = {num[i1], num[i2], num[i3], num[i4]};
                        if (result.empty() || temp != result.back()) {
                            result.push_back(temp);
                        }
                        ++i3;
                        --i4;
                    }
                }
            }
        }
        
        return result;
    }
};