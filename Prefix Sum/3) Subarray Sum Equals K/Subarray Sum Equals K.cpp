class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int,int> umap;
        umap[0] = 1;

        for(auto i:nums){
            sum += i;
            int val = sum - k;
            count += umap[val];
            umap[sum]++;
        }
        return count;
    }
};