int frog(int n, vector<int> &heights, vector<int> &mem)
{
    if(n == 0) return 0;
    if(mem[n] != -1) return mem[n];
    int minus1 = frog(n-1, heights, mem) + abs(heights[n] - heights[n-1]);

    int minus2 = n > 1 ? frog(n-2, heights, mem) + abs(heights[n] - heights[n-2]) : INT_MAX;
    
    return mem[n] = min(minus1, minus2);   
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> mem(n,-1);
    return frog(n-1, heights, mem);   
}
