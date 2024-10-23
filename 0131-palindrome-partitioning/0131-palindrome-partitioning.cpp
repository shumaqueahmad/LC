class Solution {
public:

    void func(int index, string s,vector<string>& temp, vector<vector<string>>& ans){
        // base case
        if(index== s.length()){
            ans.push_back(temp);
            return;
        }
        // index pe mujhe partition karna hai!!
        //1. check if 0-> index is palindrome?
        for(int i=index; i<s.length(); i++){
            if(isPalindrome(s,index, i)){
                temp.push_back(s.substr(index,i-index+1));
                func(i+1, s,temp,ans);
                temp.pop_back();

            }
        }
    }
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        func(0, s, temp,ans);
        return ans;
    }
};