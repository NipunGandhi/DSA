class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid, ans = nums.size();
        while (low <= high){
            mid = (low+high)/2;
            if(nums[mid] == target){
                ans = mid;
                break;
            } else if(nums[mid] > target){
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};