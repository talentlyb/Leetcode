/** First time. 4/14/2015
 */

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        vector<int> s;
        height.push_back(0);
        int i = 0;
        int j = 0;
        int result = 0;
        while (i != height.size()) {
            if (s.empty() || height[i] >= height[s.back()]) {
                s.push_back(i);
                ++i;
            }
            else {
                j = height[s.back()];
                s.pop_back();
                result = max(result, s.empty() ? i*j : (i-s.back()-1)*j);
            }
        }
        height.pop_back();
        return result;
    }
};