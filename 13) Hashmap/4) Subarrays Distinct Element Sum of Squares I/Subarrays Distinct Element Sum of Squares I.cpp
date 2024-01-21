class Solution {
public:
    int sumCounts(vector<int>& nums) {
        unordered_map<int, int> umap;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            unordered_map<int, int> umap;
            for (int j = i; j < nums.size(); j++){
                umap[nums[j]]++;
                sum += umap.size() * umap.size();
            }
        }
        return sum;
    }
};