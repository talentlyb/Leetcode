/** First time. 4/25/2015
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if (matrix.empty()) {
            return result;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int rowBegin = 0;
        int rowEnd = m - 1;
        int colBegin = 0;
        int colEnd = n - 1;
        const int UP = 0;
        const int DOWN = 1;
        const int LEFT = 2;
        const int RIGHT = 3;
        int dir = RIGHT;
        int i = 0;
        int j = 0;
        for (int k = 0; k < m*n; ++k) {
            result.push_back(matrix[i][j]);
            switch(dir) {
                case UP :
                    if (i == rowBegin) {
                        dir = RIGHT;
                        ++colBegin;
                        ++j;
                    }
                    else {
                        --i;
                    }
                    break;
                case RIGHT :
                    if (j == colEnd) {
                        dir = DOWN;
                        ++rowBegin;
                        ++i;
                    }
                    else {
                        ++j;
                    }
                    break;
                case DOWN :
                    if (i == rowEnd) {
                        dir = LEFT;
                        --colEnd;
                        --j;
                    }
                    else {
                        ++i;
                    }
                    break;
                case LEFT :
                    if (j == colBegin) {
                        dir = UP;
                        --rowEnd;
                        --i;
                    }
                    else {
                        --j;
                    }
                    break;
            }
        }
        return result;
    }
};