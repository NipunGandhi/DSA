class Solution {
public:
    int minBitFlips(int start, int goal) {
        int val = start ^ goal;
        int ans = 0;
        while(val){
            ans += val&1;
            val>>=1;
        }
        return ans;
    }
};