class Solution {
public:
    int solve(vector<vector<int>>& matrix, int& size, int row, int col, vector<vector<int>>& memo) {
        if (row == 0 || col > size) return 0;
        if (memo[row][col] != INT_MAX) return memo[row][col];

        vector<int> colActions = {-1, 0, 1};
        int ans = INT_MAX;

        for (int i = 0; i < colActions.size(); i++) {
            int val = INT_MAX;

            if (col + colActions[i] <= size && col + colActions[i] >= 1 && row >= 1) {
                val = matrix[row - 1][(col - 1) + colActions[i]] + solve(matrix, size, row - 1, col + colActions[i], memo);
            }

            ans = min(val, ans);
        }

        return memo[row][col] = ans;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int size = matrix.size();
        vector<vector<int>> memo(size + 1, vector<int>(size + 1, INT_MAX));
        int ans = INT_MAX;

        for (int i = size; i > 0; i--) {
            int recursive = solve(matrix, size, size, i, memo);
            ans = min(ans, recursive);
        }

        return ans;
    }
};
