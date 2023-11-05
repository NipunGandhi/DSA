class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adjLs(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }    

        vector<int> visited(isConnected.size(),0);
        queue<int> q;
        int count = 0;
        
        for(int i = 0; i < adjLs.size(); i++){
            if(visited[i] != 1){
                count++;
                cout<<i;
                q.push(i);
            } 
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto j:adjLs[node]){
                    if(visited[j] != 1){
                        visited[j] = 1;
                        q.push(j);
                    }
                }
            }
        }
        return count;
    }
};