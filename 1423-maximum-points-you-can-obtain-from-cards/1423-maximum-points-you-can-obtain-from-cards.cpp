class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int lefts=0,right=0,maxsum=0;
        // //BRUTE FORCE:
        // //pick i cards from begining and k-i cards from end
        // int n=nums.size();
        // for(int i=0; i<=k; i++){
        //     int startsum=0,endsum=0;

        //     for(int j=0; j<i; j++){
        //         startsum+=nums[j];
        //     }
        //     for(int j=0; j<k-i; j++){
        //         endsum+=nums[n-j-1];
        //     }
        //     maxsum=max(maxsum, startsum+endsum);
        // }
        // return maxsum;

        for(int i=0; i<k; i++){
            maxsum+=nums[i];
        }

        if(k==nums.size()) return maxsum;
        int r=nums.size()-1;
        lefts=maxsum;
        for(int i=k-1; i>=0; i--){
            lefts-=nums[i];
            right+=nums[r];
            r--;

            maxsum=max(maxsum,lefts+right);
        }
        return maxsum;
    }
};