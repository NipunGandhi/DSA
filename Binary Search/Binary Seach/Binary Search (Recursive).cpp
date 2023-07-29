#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int search(int low, int high, int k, int arr[]){
        if(low>high) return -1;
        int mid = (low+high)/2;
        if(arr[mid] == k) return mid;
        else if(arr[mid] > k) search(low, mid - 1, k, arr);
        else search(mid + 1, high, k, arr);
    }
    
    int binarysearch(int arr[], int n, int k) {
        int low = 0, high = n-1;
        return search(low,high,k,arr);
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}