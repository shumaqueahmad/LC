class Solution {
public:
    void func(int index, int n,vector<int>& nums,set<vector<int>>& unique, vector<int>& temp){
        // base case
        if(index==n){
            unique.insert(temp);
            return;
        }
        // adding to temp
        temp.push_back(nums[index]);
        func(index+1, n, nums, unique, temp);

        temp.pop_back();

        func(index+1, n, nums,unique,temp);
    }
    void func1(int ind,vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans ){
        
        ans.push_back(temp);
            
        for(int i=ind; i<nums.size(); i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            func1(i+1,nums,temp,ans);
            temp.pop_back();
        }
    }
    //new aproach using 
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> unique;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        func1(0,nums,temp,ans);
        return ans;

        //1. generating all subsets
        // func(0,n, nums,unique,temp);

        // return vector<vector<int>>(unique.begin(), unique.end());

    }
};