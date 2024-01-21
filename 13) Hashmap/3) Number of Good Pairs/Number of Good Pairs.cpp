class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> umap;
        int ans = 0;
        for(auto i:nums){
            ans += umap[i];
            umap[i]++;
        }
        return ans;
    }
};