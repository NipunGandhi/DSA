class Solution {
public:
    int findFirstOccurrence(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1, mid, ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                ans = mid;
                high = mid - 1;
            } else if (nums[mid] > target){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int findLastOccurrence(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1, mid, ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                ans = mid;
                low = mid + 1;
            } else if (nums[mid] > target){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirstOccurrence(nums,target);
        int last = findLastOccurrence(nums,target);
        return {first,last};
    }
};