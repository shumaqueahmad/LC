class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //bfs apply 
        int n=grid.size();
        int m= grid[0].size();
        queue<pair<pair<int,int>, int>>q;
        // row, col ,time
        vector<vector<int>>vis(n,vector<int>(m,0));
        //find all rotten oranges
        int fresh=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        int delrow[4]={0,-1,0,+1};
        int delcol[4]={-1,0,+1,0};
        int rotten=0;
        int maxtime=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col= q.front().first.second;
            int t= q.front().second;
            maxtime= max(maxtime,t);
            q.pop();
    
            for(int i=0; i<4; i++){
                int nrow= row+delrow[i];
                int ncol= col+delcol[i];

                if(nrow>=0&& nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]!=1){
                    q.push({{nrow,ncol}, t+1});
                    vis[nrow][ncol]=1;
                    rotten++; // to track if all fresh became rotten
                }
            }
        }

        return (rotten==fresh)?maxtime:-1;
    }
};