class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for(auto limit: queries){
            int sum = 0;
            int count = 0;

            for(int i=0; i < nums.size(); i++){
                if(sum + nums[i] <= limit){
                    count++;
                    sum += nums[i];
                }
            }
            ans.push_back(count);

        }    
        return ans;
    }
};