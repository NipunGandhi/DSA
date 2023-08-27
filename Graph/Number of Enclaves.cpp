class Solution {
public:
    void dfs(int& count, vector<vector<int>>& visited, int i, int j, vector<vector<int>>& grid){
        visited[i][j] = 1;
        count--;
        vector<int> dr = {0,0,-1,1}, dc = {-1,1,0,0};

        for(int x=0; x<4; x++){
            int row = i+dr[x];
            int col = j+dc[x];
            if(row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() && visited[row][col] == 0 && grid[row][col] == 1){
                dfs(count, visited, row, col, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) count++;
                if((i == 0 || i == n-1 || j == 0 || j == m-1) && visited[i][j] == 0 && grid[i][j] == 1){
                    dfs(count, visited, i, j, grid);
                }
            }
        } 

        return count;
    }
};