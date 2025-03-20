class Solution {
public:
    void dfs(int row, int col,vector<vector<int>>& grid,vector<vector<int>> &vis, int delrow[], int delcol[]){
        vis[row][col]=1;
        int n= grid.size();
        int m= grid[0].size();
        for(int i=0; i<4; i++){
            int nrow= row+delrow[i];
            int ncol= col+ delcol[i];
            if(nrow>=0&& nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                dfs(nrow,ncol,grid, vis,delrow,delcol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int delrow[]={0,-1,0,+1};
        int delcol[]= {-1,0,+1,0};
        // traversals:
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                if(i==0 || i==n-1||j==0||j==m-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        while(!q.empty()){
            int row= q.front().first;
            int col= q.front().second;
            q.pop();
            

            for(int i=0; i<4; i++){
            int nrow= row+delrow[i];
            int ncol= col+ delcol[i];
            if(nrow>=0&& nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                q.push({nrow,ncol});
                vis[nrow][ncol]=1;
            }
        }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    ans++;
                }
            }
        }
        return ans;
    }
};
/*
int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int delrow[]={0,-1,0,+1};
        int delcol[]= {-1,0,+1,0};
        // boundary rows:
        for(int j=0; j<m; j++){
            if(grid[0][j]==1 && vis[0][j]==0){
                dfs(0,j,grid,vis,delrow,delcol);
            }
            if(grid[n-1][j]==1 && vis[n-1][j]==0){
                dfs(n-1, j,grid,vis,delrow,delcol);
            }
        }
        // boundary cols:
        for(int i=0; i<n; i++){
            if(grid[i][0]==1 && vis[i][0]==0){
                dfs(i,0,grid,vis,delrow,delcol);
            }
            if(grid[i][m-1]==1 && vis[i][m-1]==0){
                dfs(i,m-1,grid,vis,delrow,delcol);
            }
        }

        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    ans++;
                }
            }
        }
        return ans;
*/