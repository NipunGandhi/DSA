class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 0) return 1;
        int minus1 = climbStairs(n-1);
        int minus2 = climbStairs(n-2); 
        return minus1 + minus2;      
    }
};