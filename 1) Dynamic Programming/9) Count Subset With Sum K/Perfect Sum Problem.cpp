class Solution{

	public:
	const int mod = 1000000007;

    int recursive(int arr[], int n, int sum, vector<vector<int>>& memo) {
        if(n == 0) return sum == 0;
        if(sum < 0) return 0;
        if (memo[n][sum] != -1) return memo[n][sum];
        return memo[n][sum] = (recursive(arr, n - 1, sum - arr[n - 1], memo) + recursive(arr, n - 1, sum, memo)) % mod;
    }
    
    int tab(int arr[], int n, int sum) {
        vector<vector<int>> memo(n + 1, vector<int>(sum + 1, 0));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if(i == 0) {
                    memo[i][j] = j == 0;
                    continue;
                }
                if (j - arr[i - 1] >= 0) {
                    memo[i][j] = (memo[i - 1][j - arr[i - 1]] + memo[i - 1][j]) % mod;
                } else {
                    memo[i][j] =  memo[i - 1][j] % mod;
                }
            }
        }

        return memo[n][sum];
    }

    int perfectSum(int arr[], int n, int sum) {
        // vector<vector<int>> memo(n + 1, vector<int>(sum + 1, -1));
        // return recursive(arr, n, sum, memo);
        
        return tab(arr, n, sum);
    }
};
