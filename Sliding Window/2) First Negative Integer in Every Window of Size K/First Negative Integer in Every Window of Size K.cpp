//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int arr[], long long int N, long long int K) {
    queue<int> q;
    vector<long long> ans;
    int i = 0, j = 0;
    
    while(j < N){
        if(arr[j] < 0) q.push(j);
        
        if(j - i + 1 != K){
            j++;
        } 
        else {
            if(!q.empty()){
                int element = q.front();
                ans.push_back(arr[element]);    
                if(element == i) q.pop();
            } else {
                ans.push_back(0);    
            }
            j++;
            i++;
        }
    }
    
    return ans;
 }