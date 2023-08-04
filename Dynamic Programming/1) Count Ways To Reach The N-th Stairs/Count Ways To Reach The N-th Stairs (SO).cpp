int countDistinctWays(int nStairs) {
   if(nStairs <= 1) return 1;
   int minus1 = 1, minus2 = 1, ans;
   for(int i = 2; i <= nStairs; i++){
        ans = (minus2 + minus1) % 1000000007;
        minus1 = minus2;
        minus2 = ans;
    }
   return ans;
}