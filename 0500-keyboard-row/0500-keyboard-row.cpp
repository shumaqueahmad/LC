class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int>mp;
        vector<string>ans;

        string r1="qwertyuiop";
        string r2="asdfghjkl";
        string r3="zxcvbnm";

        for(auto c:r1) mp[c]=1;
        for(auto c:r2) mp[c]=2;
        for(auto c:r3) mp[c]=3;

        for(auto word: words){
            int rowc= mp[tolower(word[0])];
            bool valid=true;

            for(auto c:word){
                if(mp[tolower(c)]!=rowc){
                    valid=false;
                    break;
                }
            }

            if(valid){
                ans.push_back(word);
            }
        }
        return ans;
    }
};