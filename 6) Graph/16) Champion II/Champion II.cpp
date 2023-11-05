// Just count in degrees
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, true);
        for(int i = 0; i < edges.size(); i++){
            visited[edges[i][1]] = false;
        }
        
        int ans = 0;
        int count = 0;
        
        for(int i = 0; i < visited.size(); i++){
            if(visited[i]){
                count++;
                ans = i;
            }
            if(count >= 2) return -1; 
        }
            
        return ans;
    }
};