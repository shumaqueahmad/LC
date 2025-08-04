class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<int> adj[]) {
        vis[node] = 1; // Mark node as visited

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n]; // Adjacency list

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0); // Correctly initialize visited array
        int cnt = 0;

        // Traverse all nodes
        for (int i = 0; i < n; i++) { // FIXED: start from i=0, not i=1
            if (vis[i] == 0) {
                cnt++;
                dfs(i, vis, adj);
            }
        }

        return cnt; // FIXED: return `cnt` instead of undefined `count`
    }
};