class Solution {
public:
    bool isPowerOfTwo(int n) {
      // O (1)
      return n > 0 && (n&n-1) == 0;

      // O (logn)
      if(n < 0) return 0;
      int count = 0;
      while(n){
          if(n & 1) count++;
          n >>= 1;
      }
      return count == 1;
    }
};