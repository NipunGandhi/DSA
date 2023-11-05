class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,-1);
        queue<int> q;

        for(int i = 0; i < n; i++){
            if(visited[i] == -1){
                q.push(i);
                visited[i] = 0;

                while(!q.empty()){
                    int element = q.front();
                    q.pop();
                    for (auto x : graph[element]) {
                        if (visited[x] == -1) {
                            q.push(x);
                            visited[x] = !visited[element];
                        } else {
                            if (visited[x] == visited[element]) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};