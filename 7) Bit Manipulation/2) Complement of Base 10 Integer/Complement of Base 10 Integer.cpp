class Solution {
public:
    int bitwiseComplement(int n) {
        unsigned int mask = ~0;
        while(n & mask) mask <<= 1;
        if(n==0) mask <<=1;
        return ~mask ^ n;
    }
};