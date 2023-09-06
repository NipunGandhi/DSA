class Solution {
public:
    long long returnHours(vector<int> piles, int timeFrame){
        long long time = 0;
        int n = piles.size();
        for(int i = 0; i < n; i++){
            time += (piles[i] / timeFrame);
            time += piles[i] % timeFrame != 0 ? 1 : 0; 
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long ans = INT_MAX;
        long long high = *max_element(piles.begin(), piles.end());
        long long low = 1, mid = 0;
        
        while(low <= high){
            mid = (low+high)/2;
            long long time = returnHours(piles, mid);

            if(time <= h){
                ans = min(ans, mid);
                high = mid-1;
            } else {
                // time > hr
                low = mid + 1;
            }
        }
        return ans;    
    }
};