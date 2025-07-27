class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m= mat[0].size();
        int maxi=-1, ind=-1;
        for(int i=0; i<n; i++){
            int count=0;
            for(int j=0; j<m; j++){
                count+=mat[i][j];
            }
            if(count>maxi){
                maxi=count;
                ind=i;
            }
        }

        return{ind,maxi};
    }
};