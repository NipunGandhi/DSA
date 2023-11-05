class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0, odd = 0, count = 0;
        while(n){
            if(n & 1){
                if(count % 2 != 0) odd++;
                else even++;
            }
            n >>= 1;
            count++;
        }
        return {even, odd};
    }
};