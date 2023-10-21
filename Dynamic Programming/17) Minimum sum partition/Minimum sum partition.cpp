class Solution{

  public:
   	int minDifference(int arr[], int n)  { 
	    int range = 0;
	    for(int i = 0; i < n; i++) range += arr[i];
	    vector<vector<bool>> memo(n + 1, vector<bool>(range + 1, false)); 
	    
	    for(int i = 0; i <= n; i++){
	        memo[i][0] = true;
	    }
	    
	    for(int i = 1; i <= n; i++){
	        for(int j = 1; j <= range; j++){
	            if(j-arr[i-1] >= 0) memo[i][j] = memo[i-1][j-arr[i-1]] || memo[i-1][j];
	            else memo[i][j] = memo[i-1][j];
	        }
	    }
	    
	    int ans = INT_MAX;
	    for(int i = 0; i <= range/2; i++){
	        if(memo[n][i] == 1){
	            ans = min(ans, abs((range-i)-i));
	        }
	    }
	    return ans;
	} 
};
