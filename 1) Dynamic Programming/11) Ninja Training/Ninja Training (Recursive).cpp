#include<bits/stdc++.h>
using namespace std;

int recursive(int days, int lastTask, vector<vector<int>> &points){
    if(days == 0){
        int maximum = INT_MIN;
        for(int i=0; i<3; i++){
            if(i!= lastTask) maximum = max(maximum, points[days][i]); 
        }
        return maximum;
    }

    int maximum = INT_MIN;

    for(int i = 0; i < 3; i++){
        if(i != lastTask) {
            int val = points[days][i] + recursive(days-1, i, points);
            maximum = max(maximum, val); 
        }
    }
    return maximum;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    return recursive(n-1, 3, points);
}