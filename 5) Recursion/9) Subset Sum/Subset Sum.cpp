class Solution{   
public:
    bool traverse(vector<int>arr, int target, int sum, int index){
        if(sum == target){
            return true;
        }
        if(sum>target || index >= arr.size()) return false;
        
        bool ans = traverse(arr, target, sum+arr[index], index+1);
        if(ans) return true;
        ans = traverse(arr, target, sum, index+1);
        if(ans) return true;
        else return false;
    }

    bool isSubsetSum(vector<int>arr, int sum){
        return traverse(arr, sum, 0, 0);
    }
};