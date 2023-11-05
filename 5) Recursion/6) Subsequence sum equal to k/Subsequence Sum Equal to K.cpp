//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution{   
public:
    bool rec(vector<int>arr, int target, int total, int index){
        if(total == target) return true;
        else if(index >= arr.size() || total>target) return false;
        
        //Pick
        total += arr[index];
        bool ans = rec(arr,target,total,index+1);
        if(ans==true) return true;
        total -= arr[index];
        
        //Not pick
        ans = rec(arr,target,total,index+1);
        return ans;
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        return rec(arr,sum,0,0);    
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends