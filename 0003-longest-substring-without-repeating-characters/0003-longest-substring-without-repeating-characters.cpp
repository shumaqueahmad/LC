class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.length();
        
        int maxlen=0;
        int l=0,r=0;
        unordered_map<char,int> m1;
        while(r<n){
            char c=s[r];
            if(m1.find(c)!=m1.end() && l<=m1[c])//mil jata hai and l is in bound
            {
                l= m1[c]+1;
            }
            maxlen=max(maxlen,r-l+1);
            m1[c]=r;
            r++;
        }
        return maxlen;
    }
};