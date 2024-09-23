class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       
        unordered_map<int,int> freq;
        for(int num:nums2){
            freq[num*k]++;
        }
        int count=0;
        for(const auto& n: nums1){
            for(const auto& x:freq){
                if(n%x.first==0){
                    count+=x.second;
                }
            }
        }
        return count;
       
        // int pairs=0;
        // for(int j=0; j<nums1.size(); j++){
        //     for(int i=0; i<nums2.size(); i++){
        //     int div=nums2[i]*k;
        //     if(nums1[j]%div==0){
        //         pairs++;
        //      }
        //     }
        // }
        // return pairs;
    }
};