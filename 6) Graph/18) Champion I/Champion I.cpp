// Follow Path
class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int res = 0, n = grid.size();
        for(int i = 1; i < n; i++){
            if(grid[res][i] == 0){
                res = i;
            }
        }
        return res;
    }
};

// Count Number of Wins
class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int count = INT_MIN;
        int ans = -1;
        for(int i = 0; i < grid.size(); i++){
            int numberOfWins = 0;
            for(int j = 0; j < grid.size(); j++){
                if(grid[i][j] != 0) numberOfWins++;
            }
            if(numberOfWins > count){
                ans = i;
                count = numberOfWins;
            }
        }
        return ans;
    }
};