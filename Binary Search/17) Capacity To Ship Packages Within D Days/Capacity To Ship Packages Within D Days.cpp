class Solution {
public:
    bool solve(int capacity, int days, vector<int>& weights){
        int count = 0;
        int total = 0;
        for(auto i:weights){
            if(total + i > capacity){
                total = i;
                count++;
            } else { 
                total += i;
            }
        }
        return count+1 <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end()); 
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans;
        while(low <= high){
            int mid = (low + high) / 2;
             if(solve(mid, days, weights)){
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};