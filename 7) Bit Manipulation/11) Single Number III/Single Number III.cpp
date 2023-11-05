class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 2) return nums;
        int setBitXor = 0, unsetBitXor = 0, dif = 0, setBitLocation = 0;
        
        // Finding XOR product of the Array
        for(auto i : nums){
            dif ^= i;
        }

        // Finding the location of difference bit
        int temp = dif;
        while((temp & 1) != 1){
            setBitLocation++;
            temp >>= 1;
        }

        // Differentiating elements according to different bit
        // And doing XOR 
        for(auto i : nums){
            if((i >> setBitLocation) & 1){
                setBitXor ^= i;
            } else {
                unsetBitXor ^= i;
            }
        }
        return {setBitXor, unsetBitXor};
    }
};