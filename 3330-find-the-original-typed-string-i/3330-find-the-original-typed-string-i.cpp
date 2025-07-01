class Solution {
public:
    int possibleStringCount(string word) {
        unordered_map<char,int>mp;

        int count=1;
        // for(int i=0; i<word.length(); i++){
        //     mp[word[i]]++;
            
        // }

        // for(auto x: mp){
        //     if(x.second>1){
        //         count+=x.second-1;
        //     }
        // }
        for(int i=1; i<word.length(); i++){
            //continuos selection
            if(word[i-1]==word[i]){
                count++;
            }
        }

        return count;
    }
};