class Solution {
public:
    int countGoodSubstrings(string s) {
        int count=0; 
        int n=s.length();
        int l=0, r=0;
        unordered_map<char,int> mp;//int->freq
        while(r<n){
           char c=s[r];
           mp[c]++;

            if(r-l+1==3){

                if(mp.size()==3){
                    count++;
                }
            
                    mp[s[l]]--;
                    if(mp[s[l]]==0) mp.erase(s[l]);
                
                    l++;
            }


           r++;
        }
        return count;

        // for(int i=0; i<n; i++){
        //     unordered_set<char> st;
        //     for(int j=i; j<n; j++){
        //         st.insert(s[j]);

        //         if(st.size()==3 && j-i+1==3){
        //             count++;
        //         }
        //         else if(st.size()>3) break;
        //         else continue;
        //     }
        // }
        
    }
};