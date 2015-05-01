/** First time. 4/30/2015
 * 
 * DFS
 */

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) {
            return true;
        }
        if (board.empty()) {
            return false;
        }
        
        int m = board.size();
        int n = board[0].size();
        vector<bool> temp (n, true);
        vector<vector<bool>> visit (m, temp);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    visit[i][j] = false;
                    if (recursive(board, visit, i, j, m, n, word.substr(1, word.length()-1))) {
                        return true;
                    }
                    visit[i][j] = true;
                }
            }
        }
        return false;
    }
    
    bool recursive(vector<vector<char>>& board, vector<vector<bool>>& visit, int i, int j, int m, int n, string word) {
        if (word.empty()) {
            return true;
        }
        if (i > 0 && visit[i-1][j] && board[i-1][j] == word[0]) {
            visit[i-1][j] = false;
            if (recursive(board, visit, i-1, j, m, n, word.substr(1, word.length()-1))) {
                return true;
            }
            visit[i-1][j] = true;
        }
        if (j > 0 && visit[i][j-1] && board[i][j-1] == word[0]) {
            visit[i][j-1] = false;
            if (recursive(board, visit, i, j-1, m, n, word.substr(1, word.length()-1))) {
                return true;
            }
            visit[i][j-1] = true;
        }
        if (i < m-1 && visit[i+1][j] && board[i+1][j] == word[0]) {
            visit[i+1][j] = false;
            if (recursive(board, visit, i+1, j, m, n, word.substr(1, word.length()-1))) {
                return true;
            }
            visit[i+1][j] = true;
        }
        if (j < n-1 && visit[i][j+1] && board[i][j+1] == word[0]) {
            visit[i][j+1] = false;
            if (recursive(board, visit, i, j+1, m, n, word.substr(1, word.length()-1))) {
                return true;
            }
            visit[i][j+1] = true;
        }
        return false;
    }
};