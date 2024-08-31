class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows<=1) return s;
        vector<string> grid(numRows);
        int i=0;
        bool flag=false;
        for(auto c:s){
            
            grid[i]+=c;
            if(i==0 || i==numRows-1){
                flag=!flag;
            }
            if(flag) i++;
            else i--;
        }
        string ans;
        for(auto x:grid){
            ans+=x;
        }
        return ans;

    
    }
};