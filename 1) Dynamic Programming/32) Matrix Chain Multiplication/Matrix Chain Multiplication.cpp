class Solution {
public:
    int solver(int arr[], int i, int j, vector<vector<int>>& memo) {
        if (i >= j) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        int ans = INT_MAX;

        for (int k = i; k < j; k++) { 
            int tempAns = solver(arr, i, k, memo) + solver(arr, k + 1, j, memo) + (arr[i - 1] * arr[k] * arr[j]);
            ans = min(ans, tempAns);
        }

        return memo[i][j] = ans;
    }

    int matrixMultiplication(int N, int arr[]) {
        vector<vector<int>> memo(N, vector<int> (N, -1));
        return solver(arr, 1, N-1, memo);
    }
};