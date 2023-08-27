//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool bfs(int V, int element, vector<int> adj[], vector<int>& visited){
        queue<pair<int, int>> q;
        q.push({element,-1});
        visited[element] = 1;
        
        while(!q.empty()){
            int top = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto i:adj[top]){
                if(visited[i] == 1){
                    if(i != parent) return true;
                } else{
                    q.push({i,top});
                    visited[i] = 1;
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited (V,0);
        for(int i=0; i<V; i++){
            if(visited[i] == 0){
                bool ans = bfs(V, i, adj, visited);
                if(ans) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends