// The floor of x is the largest element in the array which is smaller than or equal to x.
int findFloor(int low, int high, int arr[], int x){
	int ans = -1;
	while(low<=high){
		int mid = (low+high)/2;
		if(arr[mid] == x) return arr[mid];
		else if(arr[mid] < x){
			low = mid + 1;
			ans = arr[mid];
		} else {
			high = mid - 1;
		}
	}
	return ans;
}

// The ceiling of x is the smallest element in the array greater than or equal to x.
int findCeil(int low, int high, int arr[], int x, int n){
	int ans = n;
	while(low<=high){
		int mid = (low+high)/2;
		if(arr[mid] == x) return arr[mid];
		else if (arr[mid] > x){
			high = mid - 1;		
			ans = arr[mid];
		} else {
			low = mid + 1;
		}
	}
	return ans;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	int ceil = findCeil(0, n-1, arr, x, n);
	int floor = findFloor(0, n-1, arr, x);
	return {floor,ceil};
}
