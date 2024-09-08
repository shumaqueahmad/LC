class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int count=0;
        sort(nums.begin(), nums.end());
        int l=0, r=nums.size()-1;

        while(l<r){
            if(nums[l]+nums[r]<target){
                count+=r-l;
                l++;
            }
            else r--;
        }
        return count; //TC O(NLONGN)+ O(N)-> O(NLOGN)
    }
};
 // for(int i=0; i<nums.size(); i++){  BRUTE FORCE O(N^2)
        //     for(int j=i+1; j<nums.size(); j++){
        //         if(nums[i]+nums[j]<target){
        //             count++;
        //         }
        //     }
        // }