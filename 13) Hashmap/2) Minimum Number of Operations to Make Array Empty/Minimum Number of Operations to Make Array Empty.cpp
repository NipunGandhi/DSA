class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> umap;
        int ans = 0;
        for(auto i:nums){
            umap[i]++;
        }
        for(auto i:umap){
            if(i.second == 1) return -1;
            else if(i.second == 2 || i.second == 3) ans += 1;
            else {
                ans += i.second/3;
                if(i.second%3 !=0) ans+=1;
            }
        }
            
        return ans;
    }
};