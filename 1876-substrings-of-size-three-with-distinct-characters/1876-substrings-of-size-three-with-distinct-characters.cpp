class Solution {
public:
    int countGoodSubstrings(string s) {
        int count=0; 
        int n=s.length();

        for(int i=0; i<n; i++){
            unordered_set<char> st;
            for(int j=i; j<n; j++){
                st.insert(s[j]);

                if(st.size()==3 && j-i+1==3){
                    count++;
                }
                else if(st.size()>3) break;
                else continue;
            }
        }
        return count;
    }
};