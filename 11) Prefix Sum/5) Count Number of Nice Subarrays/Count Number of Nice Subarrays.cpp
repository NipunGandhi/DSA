class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> umap;
        umap[0] = 1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
          sum += nums[i] % 2;
          int val = sum - k;
          if(umap.find(val) != umap.end()){
            ans += umap[val];
          }
          umap[sum]++;
        }

        return ans;
    }
};