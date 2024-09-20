class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.length();
        
        int maxlen=0;
        int l=0,r=0;
        unordered_map<char,int> m1;
        while(r<n){
            char c= s[r];
            if(m1.find(c)!=m1.end() && m1[c]>=l){ //eleemt found and its last seen value is more than l
            /*REASON FOR L UDATION CONDITION:
            For each character s[r], check if it exists in the map and whether its last 
            occurrence index is within the current window (l <= m1[c])*/
            l=m1[c]+1;
            }

            m1[c]=r;
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};