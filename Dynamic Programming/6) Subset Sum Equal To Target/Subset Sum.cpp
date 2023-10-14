class Solution{   
public:
    bool recursion(vector<int>arr, int sum, int index, vector<vector<int>> &memo){
        if(sum == 0) return true;
        if(index < 0 || sum < 0) return false;
        
        if(memo[index][sum] != -1) return memo[index][sum]; 
        return memo[index][sum] = recursion(arr, sum - arr[index], index - 1, memo) || recursion(arr, sum, index - 1, memo);
    }
    
    bool tab(vector<int> arr, int sum) {
        vector<vector<int>> memo(arr.size() + 1, vector<int>(sum + 1, 0));
    
        for (int i = 0; i <= arr.size(); i++) {
            memo[i][0] = true;
        }
    
        for (int i = 1; i <= arr.size(); i++) {
            for (int j = 1; j <= sum; j++) {
                if(i-1 >= 0){
                    memo[i][j] = memo[i-1][j];
                    if(j-arr[i-1] >= 0){
                        memo[i][j] = memo[i-1][j] || memo[i-1][j-arr[i-1]];      
                    }
                }
                
            }
        }
        return memo[arr.size()][sum];
    }

    
    
    bool isSubsetSum(vector<int>arr, int sum){
        // vector<vector<int>> memo(arr.size(), vector<int>(sum+1, -1));
        // return recursion(arr, sum, arr.size() - 1, memo);
        return tab(arr, sum);
    }
};
