class Solution {
public:
    int solve(int ind, vector<int>&nums, int k, vector<int>&ans,int n){
        if(ind>=n) return 0;
        if(ans.size()>k) return 0;

        //pick nonpick
        ans.push_back(nums[ind]);
        int pick=nums[ind]+solve(ind+1,nums,k,ans,n);
        ans.pop_back();
        int nonpick= solve(ind+1,nums,k,ans,n);

        return max(pick,nonpick);
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i=0; i<n; i++){
            pq.push({nums[i],i});
            if(pq.size()>k){
                pq.pop();
            }
        }

        //retrive top k elements
        vector<pair<int,int>>vec;
        while(!pq.empty()){
            vec.push_back(pq.top());
            pq.pop();
        }
        sort(vec.begin(),vec.end(), [](auto& a, auto& b){
            return a.second<b.second;
        });

        for(auto& a:vec){
            ans.push_back(a.first);
        }
        return ans;

    }
};