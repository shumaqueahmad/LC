class Solution {
public:
    int mod=1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        //precompute pow
        vector<int>pow(n,1);
        for(int i=1;i<n; i++){
            pow[i]= (pow[i-1]*2)%mod;
        }
        //sort
        sort(nums.begin(), nums.end());
        //left and right initialization
        int left=0;
        int right=n-1;  
        int count=0;
        while(left<=right){
            if(nums[left]+nums[right]<=target){
                count=(count+pow[right-left])%mod;
                left++; //alwasys inclusive of left element
            }
            else right--;
        }

        return count;
    }
};