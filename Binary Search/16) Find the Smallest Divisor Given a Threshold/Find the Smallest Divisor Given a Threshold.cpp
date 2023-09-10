class Solution {
public:
    int smallestDivisorLogic(vector<int>& nums, int divisor){
        int sum = 0;
        for(auto i:nums){
            sum += (i / divisor);
            sum += i % divisor == 0 ? 0 : 1; 
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(),nums.end()), mid=0;
        int ans;
        while(low <= high){
            mid = (low+high)/2;
            int val = smallestDivisorLogic(nums, mid);
            if(val > threshold){
                low = mid+1;
            } else {
                high = mid-1;
                ans = mid;
            }
        }
        return ans;
    }
};