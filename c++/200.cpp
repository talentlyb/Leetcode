/** First time. 4/15/2015
 * 
 * Depth-first search.
 */

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.size() == 0) {
            return 0;
        }
        
        int m = grid.size();
        int n = grid[0].size();
        int i, j;
        int num = 0;
        vector<bool> temp (n, false);
        vector<vector<bool>> island (m, temp);
        
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !island[i][j]) {
                    ++num;
                    mark(grid, island, i, j, m, n);
                }
            }
        }
        
        return num;
    }
    
    void mark(vector<vector<char>> &grid, vector<vector<bool>> &island, int i, int j, int m, int n) {
        island[i][j] = true;
        if (i > 0 && grid[i-1][j] == '1' && !island[i-1][j]) {
            mark(grid, island, i-1, j, m, n);
        }
        if (i < m-1 && grid[i+1][j] == '1' && !island[i+1][j]) {
            mark(grid, island, i+1, j, m, n);
        }
        if (j > 0 && grid[i][j-1] == '1' && !island[i][j-1]) {
            mark(grid, island, i, j-1, m, n);
        }
        if (j < n-1 && grid[i][j+1] == '1' && !island[i][j+1]) {
            mark(grid, island, i, j+1, m, n);
        }
    }
};