class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=0;
        unordered_map<int,int> m1;
        for(auto x:nums){
            m1[x]++;
        }
        int count=0;
        for(auto x:m1){
            if(x.second>count){
                ele=x.first;
                count=x.second;
            }
        }
        return ele;
    }
};