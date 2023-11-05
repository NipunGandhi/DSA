#include <bits/stdc++.h> 
bool recursion(int index, int total,int target, vector<int> &arr){
    if(total == target) return true;
    if(total > target || index == arr.size()) return false;

    //pick
    bool ans = recursion(index+1, total+arr[index], target, arr);
    if(ans) return ans;
    //not pick
    ans = recursion(index+1, total, target, arr);
    return ans;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    return recursion(0,0,k,arr);
}