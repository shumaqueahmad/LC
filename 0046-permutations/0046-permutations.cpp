class Solution {
public:
    void func(vector<int>&temp, int freq[], vector<vector<int>>&ans,vector<int>& nums){
        //base case
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(freq[i]==0){
                temp.push_back(nums[i]);
                freq[i]=1;
                func(temp,freq,ans,nums);
                freq[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        int freq[nums.size()];
        for(int i=0; i<nums.size(); i++) freq[i]=0;
        func(temp,freq,ans,nums);
        return ans;
    }
};