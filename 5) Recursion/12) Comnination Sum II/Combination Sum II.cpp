class Solution {
public:
    void traverse(vector<vector<int>>& ans, vector<int>& arr, vector<int> temp, int index, int sum, int target){
        if(target==sum){
            ans.push_back(temp);
            return;
        } 
        if(target < sum) return;
        for(int i = index; i < arr.size(); i++){
            if(i != index && arr[i] == arr[i-1]) continue;
            temp.push_back(arr[i]);
            traverse(ans, arr, temp, i+1, sum+arr[i], target);
            temp.pop_back();    
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        traverse(ans, candidates, {}, 0, 0, target);
        return ans;
    }
};