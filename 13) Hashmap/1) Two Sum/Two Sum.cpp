// Brute force - O(n^2)
// Better - O(nlogn) Two Pointer + Sorting + Then find index
// Optimised - O(n) Hashmap

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        for(int i = 0; i<nums.size(); i++){
            int diff = target - nums[i];
            if(umap.find(nums[i]) != umap.end()){
                return {umap[nums[i]], i};
            } else {
                umap[diff] = i;
            }
        }
        return {};
    }
};