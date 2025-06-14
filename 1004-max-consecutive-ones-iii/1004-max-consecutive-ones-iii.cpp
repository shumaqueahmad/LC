class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //convert the question to subarray with max k zeros
        int maxlen=0;
        //using sliding window
        int l=0, r=0;
        int n=nums.size();
        int zeros=0;
        
        while(r<n){
            if(nums[r]==0){
                zeros++;
            }
            while(zeros>k){
                if(nums[l]==0){
                    zeros--;
                }
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }


        return maxlen;
    }
};

/* O(n^2) solution
for(int i=0; i<nums.size();i++){
            int zeros=0;
            for(int j=i; j<nums.size(); j++){
                if(nums[j]==0){
                    zeros++;
                }
                if(zeros<=k){
                    int len=j-i+1;
                    maxlen=max(maxlen,len);
                }
                else
                break;
            }
        }
*/