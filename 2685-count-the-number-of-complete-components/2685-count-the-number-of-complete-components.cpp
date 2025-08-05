class Solution {
public:
    void dfs(vector<int> adj[], vector<int>& vis, int node, int &n, int &edgecount){
        vis[node]=1;
        n++;
        edgecount+=adj[node].size();
        for(auto edge: adj[node]){
            if(!vis[edge]){
                dfs(adj, vis,edge,n,edgecount);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto edge:edges){
            int u= edge[0];
            int v= edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        int ans=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                vis[i]=1;
                int n=0;
                int edgecount=0;
                dfs(adj,vis,i, n, edgecount);
                if(n*(n-1)==edgecount) ans++;
            }
        }
        return ans;
    }
};