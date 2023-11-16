class Solution
{
    public:
    unsigned int reverseBits(unsigned int n)
    {
        int ans = 0;
        while(n){
            if(n & 1){
                ans <<= 1;
                ans |= 1;
            } else {
                ans <<= 1;
            }
            n >>= 1;
        }
        return ans;
    }
};