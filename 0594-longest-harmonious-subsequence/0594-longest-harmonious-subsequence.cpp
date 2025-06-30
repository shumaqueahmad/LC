class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=1;
        if(n<=1) return 0;
        sort(nums.begin(), nums.end());
        int maxlen=0;
        while(r<n && l<n){
            if(nums[r]-nums[l]==1){
                maxlen= max(maxlen,r-l+1);
                r++;
            }
            else if(nums[r]-nums[l]<1){
                r++;
            }
            else l++;
        }

        return maxlen;
    }
};