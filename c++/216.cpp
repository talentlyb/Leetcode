// First time. 2016/1/17
// Backtracking

class Solution {
public:
    void backTracking(int k, int n, int st, vector<vector<int>> &result, vector<int> &solution) {
        if (k == 0 && n == 0) {
            result.push_back(solution);
            return;
        }
        if (k <= 0) {
            return;
        }
        for (int i = st; i <= 9; ++i) {
            if (i <= n) {
                solution.push_back(i);
                backTracking(k-1, n-i, i+1, result, solution);
                solution.pop_back();
            }
            else {
                break;
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> solution;
        backTracking(k, n, 1, result, solution);
        return result;
    }
};
