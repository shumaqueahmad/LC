class Solution {
public:
    int solve(vector<int>& nums, int k){
        int l=0, r=0, count=0;
        int n= nums.size();
        unordered_map<int,int>mp; // no,freq

        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int a= solve(nums,k);
        int b= solve(nums, k-1);
        return a-b;
    }
};