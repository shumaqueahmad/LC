class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums){
            if(it%2==0) mp[it]++;
        }
        int ans=INT_MAX;
        int maxfreq=0;
        for(auto it: mp){
            int ele=it.first;
            int freq= it.second;
            if(freq>maxfreq){
                ans=ele;
                maxfreq=freq;
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};