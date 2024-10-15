class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int>ans(encoded.size()+1);
        ans[0]=first;

        for(int i=0; i<encoded.size();i++){
            if(ans[i]==encoded[i]){
                ans[i+1]=0;
            }
            else{
                ans[i+1]=ans[i]^encoded[i];
            }
            
        }
        return ans;
    }
};