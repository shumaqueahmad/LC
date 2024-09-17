class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size(); //ye obs hai mere paas
        //int n -> these obs went missing
        int sum=accumulate(rolls.begin(),rolls.end(),0);

        int total=mean*(n+m);
        int rem=total-sum;
        vector<int>ans;

        if(rem<n || rem>n*6) return {};
        else{
            int min=rem/n; // 
            int extra=rem%n; // extra number of 1's we need 
            for(int i=0; i<n; i++){
                if(extra>0) ans.push_back(min+1);
                else ans.push_back(min);
                extra=max(0, extra-1);
            }
        }
        return ans;
        
    }
};