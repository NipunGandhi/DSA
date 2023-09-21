class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n,1);
        int count = 0;
        for(int i = 2; i < n; i++){
          if(isPrime[i]){
            count++;
            for(int j = 2; j * i < n; j++){
              isPrime[j*i] = 0;
            }
          }
        }
        return count;
    }
};