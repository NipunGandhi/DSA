class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int low = 0, high = n - 1, mid, ans = nums[0];
        while(low <= high){
            mid = (low+high)/2;
            ans = min(ans,nums[mid]);
            if(nums[low] <= nums[mid]){
                ans = min(ans,nums[low]);
                low = mid + 1;
            } else {
                ans = min(ans,nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};