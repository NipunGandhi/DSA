class Solution {
public:
    void traverse(vector<int>& nums, vector<vector<int>>& ans, vector<int> temp, int index){
        if(index >= nums.size()) return;

        //Pick
        temp.push_back(nums[index]);
        traverse(nums, ans, temp,index+1);
        ans.push_back(temp);
        temp.pop_back();
        
        //No Pick
        traverse(nums, ans, temp,index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        traverse(nums,ans, {}, 0);
        return ans;
    }
};