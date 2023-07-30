int upperBound(vector<int> arr, int x, int n) {
	int low = 0, high = arr.size() - 1, ans = n, mid = 0;
	while(low<=high){
		mid = (low+high)/2;
		if(arr[mid] > x) {
			ans = mid;
			high = mid-1;
		} else {
			low = mid+1;
		}
	}
	return ans;
}
