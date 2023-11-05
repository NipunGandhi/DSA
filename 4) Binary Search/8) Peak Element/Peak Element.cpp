class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        if(arr.size() == 1) return 0;
        if(arr[0] > arr[1]) return 0;
        if(arr[arr.size() - 1] > arr[arr.size() - 2]) return arr.size() - 1;
        // Shrinking because have solved few cases from above conditions
        int low = 1, high = arr.size() - 2, mid = 0;
        while(low <= high){
            mid = (low+high)/2;
            if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid - 1]) return mid;
            else if(arr[mid] > arr[mid+1]){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return 0;
    }
};