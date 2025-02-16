class Solution {
private:
    void dfs(int row, int col,vector<vector<char>>& board,vector<vector<int>> &vis, int delrow[], int delcol[]){
        vis[row][col]=1;
        int n= board.size();
        int m= board[0].size();
        for(int i=0; i<4; i++){
            int nrow= row+delrow[i];
            int ncol= col+ delcol[i];
            if(nrow>=0&& nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,board, vis, delrow,delcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m= board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));// vis matrix
        int delrow[]={0,-1,0,+1};
        int delcol[]= {-1,0,+1,0};
        // traversing first and last row
        for(int j=0; j<m; j++){
            if(board[0][j]=='O' && vis[0][j]==0){
                dfs(0,j,board,vis,delrow,delcol);   
            }
            if(board[n-1][j]=='O' && vis[n-1][j]==0){
                dfs(n-1, j, board, vis,delrow,delcol);
            }
        }
        for(int i=0; i<n;i++){
            if(board[i][0]=='O' && vis[i][0]==0){
                dfs(i,0,board,vis,delrow,delcol);
            }
            if(board[i][m-1]=='O' && vis[i][m-1]==0){
                dfs(i,m-1,board,vis,delrow,delcol);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};