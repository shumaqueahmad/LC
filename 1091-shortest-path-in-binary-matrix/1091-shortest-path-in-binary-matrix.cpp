class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        if(n==1 && m==1 && grid[0][0]==0) return 1;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        int src=grid[0][0];
        int dest=grid[n-1][m-1];
        if(src!=0 ||dest !=0) return -1;
        
        queue<pair<int, pair<int,int>>>q;
        q.push({0, {0,0}});
        dist[0][0]=0;
        int delr[]={0,-1,-1,-1,0,+1,+1,+1};
        int delc[]={-1,-1,0,+1,+1,+1,0,-1};
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            int row= it.second.first;
            int col= it.second.second;
            int d=it.first;

            for(int i=0; i<8; i++){
                int nrow= row+delr[i];
                int ncol= col+delc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && 
                d+1<dist[nrow][ncol]){
                    dist[nrow][ncol]=d+1;
                    if(nrow==n-1 && ncol==m-1) return dist[nrow][ncol]+1; 
                    q.push({d+1, {nrow,ncol}});
                }
            }
        }
        return -1;

    }
};