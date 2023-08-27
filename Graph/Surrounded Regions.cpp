class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size() , m = board[0].size();
        vector<vector<int>> visited (n , vector<int>(m, 0));
        vector<int> dr = {-1,1,0,0}, dc = {0,0,-1,1};
        vector<vector<char>> cboard(n, vector<char>(m, 'X'));
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O') {
                q.push({i,0});
                visited[i][0] = 1;
                cboard[i][0] = 'O';
            }
            if(board[i][m-1] == 'O' && m-1 != 0){
                q.push({i,m-1});
                visited[i][m-1] = 1;
                cboard[i][m-1] = 'O';
            } 
        }

        for(int i = 0; i < m; i++) {
            if(board[0][i] == 'O'){
                q.push({0,i});
                visited[0][i] = 1;
                cboard[0][i] = 'O';
            } 
            if(board[n-1][i] == 'O' && m-1 != 0){
                q.push({n-1,i});
                visited[n-1][i] = 1;
                cboard[n-1][i] = 'O';
            } 
        }

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int row = r + dr[i];
                int col = c + dc[i];
                if(row >= 0 && col >= 0 && row < n  && col < m && visited[row][col] == 0 && board[row][col] == 'O'){
                    visited[row][col] = 1;
                    cboard[row][col] = 'O';
                    q.push({row,col});
                }
            }
        }

        board = cboard;
    }
};