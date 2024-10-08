class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1, amount+1);
        dp[0]=0;

        for(int coin:coins){
            for(int i= coin; i<=amount; i++){
                dp[i]=min(dp[i], dp[i-coin]+1);
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
       // int ans=0;
        // sort(coins.begin(), coins.end());
        // for(int i=n-1; i>=0; i--){
        //     if(amount>=coins[i]){
        //         ans+=amount/coins[i];
        //         amount%=coins[i];
        //     }
        // }
        //  return (amount == 0) ? ans : -1;
        
    }
};