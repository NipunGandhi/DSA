#include <bits/stdc++.h> 

int findAnswer(int nStairs, vector<int> &mem){
    if(nStairs == 0) return 1;
    if(nStairs < 0) return 0;
    
    if(mem[nStairs] != -1) return mem[nStairs];

    int minus1 = findAnswer(nStairs-1,mem) % 1000000007;
    int minus2 = findAnswer(nStairs-2,mem) % 1000000007;

    return mem[nStairs] = (minus1 + minus2) % 1000000007;
}

int countDistinctWays(int nStairs) {
    vector<int> mem(nStairs+1,-1);
    return findAnswer(nStairs,mem);    
}