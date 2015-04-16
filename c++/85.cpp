/** First time. 4/15/2015
 * 
 * Dynamic programming. Calculate maximal rectangle for each (i,j).
 * Perform calculation row by row.
 */

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty()) {
            return 0;
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;
        int i, j, curr_left, curr_right;
        vector<int> left (n, 0);
        vector<int> right (n, n);
        vector<int> height (n, 0);
        for (i = 0; i < m; ++i) {
            curr_left = 0;
            curr_right = n;
            for (j = 0; j < n; ++j) {   // calculate left
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], curr_left);
                }
                else {
                    left[j] = 0;
                    curr_left = j + 1;
                }
            }
            for (j = n-1; j >= 0; --j) {    // calculate right
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], curr_right);
                }
                else {
                    right[j] = n;
                    curr_right = j;
                }
            }
            for (j = 0; j < n; ++j) {   // calculate height
                if (matrix[i][j] == '1') {
                    height[j]++;
                }
                else {
                    height[j] = 0;
                }
            }
            for (j = 0; j < n; ++j) {   // calculate maximal rectangle area
                result = max(result, (right[j]-left[j])*height[j]);
            }
        }
        return result;
    }
};