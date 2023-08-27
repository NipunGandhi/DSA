class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0, time = 0, totalRotten = 0;
        queue<pair<pair<int, int>,int>> q;
        vector<vector<int>> visited (n, vector(m, 0));
        vector<int> deltaRow = {0,0,-1,1}, deltaColumn = {-1,1,0,0};
        
        // Pushing initial rotten tomatoes in queue
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},time});
                    visited[i][j] = 1;
                } else if(grid[i][j] == 1){
                    count += 1;
                }
            }
        }

        // Traversing + Marking them
        while(!q.empty()){
            int t = q.front().second;
            int r = q.front().first.first;
            int c = q.front().first.second;
            q.pop();
            time = max(time,t);
            for(int i = 0; i < 4; i++){
                int row = r + deltaRow[i], column = c + deltaColumn[i];
                if(row >= 0 && column >=0 && row < n && column < m && visited[row][column] == 0 && grid[row][column] == 1){
                    visited[row][column] = 1;
                    q.push({{row,column},t+1});
                    totalRotten++;
                }
            }            
        }

        if(count != totalRotten) return -1;
        return time;
    }
};