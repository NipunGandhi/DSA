class Solution {
public:
    long long remove(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& values){
        if(visited[node]) return 0;
        visited[node] = 1;
        long long mn = 0;
        
        for(auto i: adj[node]){
            mn += remove(i, adj, visited, values);
        }

        if(mn == 0) return values[node];
        return min(values[node] + 0ll, mn);
    }

    long long treeTotal(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& values){
        if(visited[node]) return 0;
        visited[node] = 1;
        long long sum = values[node];
        
        for(auto i: adj[node]){
            sum += treeTotal(i, adj, visited, values);
        }
        
        return sum;
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> adj(n + 1);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited (n + 1, 0);

        long long total = treeTotal(0, adj, visited, values);
        for(int i = 0; i < n; i++) visited[i] = 0;
        long long min = remove(0, adj, visited, values);
        
        return total - min;
    }
};