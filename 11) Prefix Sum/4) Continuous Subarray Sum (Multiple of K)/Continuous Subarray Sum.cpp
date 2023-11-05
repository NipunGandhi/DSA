class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        // Remainder, Index
        unordered_map<int,int> umap;
        umap[0] = -1;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int remainder = sum % k;
            if(umap.find(remainder) != umap.end()){
                if(umap[remainder]+1 < i){
                    return true;
                }
            } else {
                umap[remainder] = i;
            }
        }

        return false;
    }
};