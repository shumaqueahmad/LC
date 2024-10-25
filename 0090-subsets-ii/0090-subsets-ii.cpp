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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> unique;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<int> temp;
        //1. generating all subsets
        func(0,n, nums,unique,temp);

        return vector<vector<int>>(unique.begin(), unique.end());

    }
};