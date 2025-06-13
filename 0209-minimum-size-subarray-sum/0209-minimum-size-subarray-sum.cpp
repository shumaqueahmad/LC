class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int l=0, r=0, sum=0;
        int ans=INT_MAX;
        int n=nums.size();
        while(r<n){
            
            sum+=nums[r];
            //exclusion part wise
            while(sum>=target){
                    ans=min(ans,r-l+1);
                    sum-=nums[l];
                    l++;
                }
                r++;
                
        }
        return (ans!=INT_MAX)? ans:0;
    }
};