class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>>& visited, int currentColor){
        visited[sr][sc] = 1;
        image[sr][sc] = color;

        vector<int> deltaRow = {0, 1 , -1, 0};
        vector<int> deltaColumn = {-1, 0, 0, 1};
        
        for(int i=0; i < 4; i++){
            int row = sr + deltaRow[i];
            int column = sc + deltaColumn[i];
            if(row >= 0 && column >= 0 && row < image.size() && column < image[0].size() && visited[row][column] != 1 && image[row][column] == currentColor){
                dfs(image, row, column, color, visited, currentColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int currentColor = image[sr][sc];
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), 0));
        dfs(image, sr, sc, color, visited, currentColor);
        return image;
    }
};