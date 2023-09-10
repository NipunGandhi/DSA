class NumMatrix {
public:
    vector<vector<int>> pf;
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        pf = vector(row, vector<int>(col, 0));
        pf[0][0] = matrix[0][0];

        for(int i = 1; i < row; i++) pf[i][0] = matrix[i][0] + pf[i-1][0];
        for(int i = 1; i < col; i++) pf[0][i] = matrix[0][i] + pf[0][i-1];

        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                pf[i][j] = matrix[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];  
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = pf[row2][col2];
        
        if(row1 - 1 >= 0) {
            total = total - pf[row1 - 1][col2];
        }
        if(col1 - 1 >= 0) {
            total = total - pf[row2][col1 - 1];
        }
        if(row1 - 1 >= 0 && col1 - 1 >= 0) {
            total = total + pf[row1 - 1][col1 - 1];
        }
        return total;
    }
};