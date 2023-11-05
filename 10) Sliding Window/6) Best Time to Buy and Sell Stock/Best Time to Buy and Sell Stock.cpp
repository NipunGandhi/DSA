class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1) return 0; 
        int left = prices[0], right;
        int ans = 0;
        for(int i = 1; i < n; i++){
            right = prices[i];
            ans = max(ans,right - left);
            if(right < left){
                left = right;
            }
        }
       return ans; 
    }
};