int tab(int nStairs){
    vector<int> mem(nStairs+1,1);
    mem[1] = 1;
    mem[2] = 2;
    if(nStairs<=2) return mem[nStairs];
    for(int i = 3; i <= nStairs; i++){
        mem[i] = (mem[i-1] + mem[i-2]) % 1000000007;
    }
    return mem[nStairs] % 1000000007;
}

int countDistinctWays(int nStairs) {
    return tab(nStairs);    
}