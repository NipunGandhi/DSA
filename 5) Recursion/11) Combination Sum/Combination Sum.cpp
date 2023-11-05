class Solution {
public:
    void traverse(vector<vector<int>>& ans, vector<int> arr, int target, int sum, int index, vector<int> temp){
        if(sum == target){
            ans.push_back(temp);
            return;
        } 
        if(sum > target || index >= arr.size()) return;

        //Pick
        temp.push_back(arr[index]);
        traverse(ans,arr,target,sum+arr[index],index,temp);
        temp.pop_back();
        
        //Don't Pick
        traverse(ans,arr,target,sum,index+1,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        traverse(ans,candidates,target,0,0, {});
        return ans;
    }
};