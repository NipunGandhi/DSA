int mem(int days, int lastTask, vector<vector<int>> &points, vector<vector<int>> memo){
    if(days == 0){
        int maximum = INT_MIN;
        for(int i=0; i<3; i++){
            if(i!= lastTask) maximum = max(maximum, points[days][i]); 
        }
        return maximum;
    }
    if(memo[days][lastTask] != -1) return memo[days][lastTask];
    int maximum = INT_MIN;

    for(int i = 0; i < 3; i++){
        if(i != lastTask) {
            int val = points[days][i] + mem(days-1, i, points, memo);
            maximum = max(maximum, val); 
        }
    }
    return memo[days][lastTask] = maximum;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector <int>> memo(n, vector <int>(4,-1));
    return mem(n-1, 3, points, memo);
}
