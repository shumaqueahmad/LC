class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int ,int> map1;
       vector<int> ans;
       int rem=0;
       for(int i=0; i<nums.size();i++)
       {
        rem=target-nums[i];
        if(map1.find(rem)==map1.end())
        {
            pair<int,int> p;
            p.first=nums[i];
            p.second=i;
            map1.insert(p);
        }
        else{
            ans.push_back(i);
            ans.push_back(map1[rem]);
        }
       }
       return ans;

       
       /* int remaining=0;
        int n= nums.size();
        std::vector<int> indexes;
        for(int i=0; i<n; i++)
        {
            int remaining= target-nums[i];
            for(int j=i+1; j<n;j++)
            {
                if(nums[j]==remaining)
                {
                    indexes.push_back(i);
                    indexes.push_back(j);

                    
                }
            }
        }
        return indexes;*/
    }
};