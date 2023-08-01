class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n = arr.size();
        if(n == 1) return arr[0] == target;
        int low = 0, high = n - 1, mid;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid] == target) return 1;
            if(arr[mid] == arr[low] && arr[high] == arr[mid]){
                low += 1;
                high -= 1;
            } else if (arr[low] <= arr[mid]){
                if(arr[low] <= target && arr[mid] >= target){
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
               if(arr[mid] <= target && arr[high] >= target){
                    low = mid + 1;
                } else {
                    high = mid - 1;
                } 
            }
        }
        return 0;
    }
};