class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int pairs=0;
        for(int j=0; j<nums1.size(); j++){
            for(int i=0; i<nums2.size(); i++){
            int div=nums2[i]*k;
            if(nums1[j]%div==0){
                pairs++;
             }
            }
        }
        return pairs;
    }
};