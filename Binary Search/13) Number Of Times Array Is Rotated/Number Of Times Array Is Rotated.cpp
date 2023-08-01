int findKRotation(vector<int> &arr){
    int n = arr.size();
    if(n == 1) return 0;
    int low = 0, high = n-1, mid, ans = arr[0], aIndex = 0;
    
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid] < ans){
            ans = arr[mid];
            aIndex = mid;
        }
        if(arr[low] <= arr[mid]){
            if(arr[low] < ans){
                ans = arr[low];
                aIndex = low;
            }
            low = mid + 1;
        } else {
            if(arr[mid] < ans){
                ans = arr[mid];
                aIndex = mid;
            }
            high = mid - 1;
        }
    }
    return aIndex; 
}