class Solution {
public:
    char kthCharacter(int k) {
        string word="a";
        while(word.length()<k){
            string temp="";
            for(char c:word){
                char nextchar= 'a'+(c-'a'+1)%26;
                temp+=nextchar;
            }
            word+=temp;
        }
        return word[k-1];
    }
};