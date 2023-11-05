class Solution {
public:
    int find(int k, int n, vector<vector<int>> &memo){
        if(n == 0 || n == 1) return n;
        if(k == 1) return n;
        if(memo[k][n] != -1) return memo[k][n];
        
        int ans = INT_MAX;
        int low = 1, high = n;
        int temp = 0;
        
        while(low <= high){
            int mid = (low + high) / 2;
            int eggBroken = 0, notBroken = 0;
            
            if(memo[k-1][mid - 1] != -1){
                eggBroken = memo[k-1][mid - 1];
            } else {
                eggBroken = find(k - 1, mid - 1, memo);
                memo[k-1][mid - 1] = eggBroken;
            } 
            
            if(memo[k][n - mid] != -1){
                notBroken = memo[k][n - mid];
            } else {
                notBroken = find(k, n - mid, memo);
                memo[k][n - mid] = notBroken;
            } 
            
            temp = 1 + max(eggBroken, notBroken);
            
            if(eggBroken < notBroken){
                low = mid + 1;
            } else {
                high = mid - 1;
            }

            ans = min(ans, temp);
        }
        
        return memo[k][n] = ans;
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> memo(k + 1,vector<int> (n + 1,-1));
        return find(k , n, memo);
    }
};