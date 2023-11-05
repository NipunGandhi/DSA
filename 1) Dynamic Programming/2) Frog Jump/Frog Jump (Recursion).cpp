#include <bits/stdc++.h> 

int frog(int n, vector<int> &heights)
{
    if(n == 0) return 0;

    int minus1 = frog(n-1, heights) + abs(heights[n] - heights[n-1]);

    int minus2 = n > 1 ? frog(n-2, heights) + abs(heights[n] - heights[n-2]) : INT_MAX;
    
    return min(minus1, minus2);   
}

int frogJump(int n, vector<int> &heights)
{
    return frog(n-1, heights);   
}
