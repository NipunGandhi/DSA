class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            int count = 0;
            int number = i;
            while(number){
                if(number&1) count++;
                number>>=1;
            }
            if(count == k) sum += nums[i];
        }
        return sum;
    }
};