string findLCS(int n, int m,string &s1, string &s2){
	vector<vector<int>> memo(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i - 1] == s2[j - 1]) memo[i][j] = 1 + memo[i - 1][j - 1];
            else memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
        }
    }

    string ans = "";
	for(int i = 0; i <memo[n][m]; i++) ans += 'a';
	
	int index = memo[n][m] - 1;
    while(n > 0 && m > 0){
        if(s1[n - 1] == s2[m - 1]){
            ans[index] = s1[n - 1];
			index--;
            m--;
            n--;
        } 
        else if(memo[n - 1][m] >= memo[m][n - 1]){
            n--;
        }
        else{
            m--;
        }
    }
    return ans;
} 