class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        unordered_map<string,string>mp;
        vector<string>ans;
        for(auto temp:words){
            string x=temp;
            sort(temp.begin(), temp.end());
            if(mp.find(temp)==mp.end()){
                mp[temp]=x;
                ans.push_back(x);
            }
        }
       return ans;

    }
};