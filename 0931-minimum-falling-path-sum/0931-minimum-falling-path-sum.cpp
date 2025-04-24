class Solution {
public:
    int solve(int i, int j,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        //Base Case
        if(i<0 || j<0|| j>=n) return 1e9;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up= matrix[i][j]+ solve(i-1,j,n,matrix,dp);
        int ld=matrix[i][j]+ solve(i-1, j-1,n, matrix,dp);
        int rd= matrix[i][j]+ solve(i-1,j+1,n,matrix,dp);

        return dp[i][j]= min(up,min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=1e9;
        //vector<vector<int>>dp(n,vector<int>(n,-1));
        vector<vector<int>>dp(n,vector<int>(n,0));
        //tabulation
        for(int i=0; i<n; i++){
            dp[0][i]= matrix[0][i]; //base case initialization
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int up= matrix[i][j]+  dp[i-1][j];

                int ld=matrix[i][j];
                if(j-1>=0) ld+= dp[i-1][j-1];
                else ld+=1e9;

                int rd= matrix[i][j];
                if(j+1<n)rd+= dp[i-1][j+1];
                else rd+=1e9;

                dp[i][j]= min(up,min(ld,rd));
            }
        }

        // for(int i=0;i<n; i++){
        //     mini= min(mini,solve(n-1,i,n,matrix,dp));
        // }
        for(int i=0;i<n; i++){
            mini= min(mini,dp[n-1][i]);
        }
        return mini;
    }
};