#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(vector<pair<int,int>>& path, vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j, int basei, int basej){
        visited[i][j] = 1;
        path.push_back({i-basei, j-basej});
        
        vector<int> dr = {-1,1,0,0}, dc = {0,0,-1,1};
        
        for(int x=0; x<4; x++){
            int r = dr[x] + i;
            int c = dc[x] + j;
            
            if(r>=0 && c>=0 && r < grid.size() && c < grid[0].size() && visited[r][c] == 0 && grid[r][c] == 1){
                dfs(path,grid,visited,r,c,basei,basej);
            }
        }
    }  
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        vector<pair<int,int>> path;
        set <vector<pair<int,int>>> a;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    dfs(path,grid,visited,i,j,i,j);
                    a.insert(path);
                    path = {};
                }
            }
        }
        return a.size();
    }
};