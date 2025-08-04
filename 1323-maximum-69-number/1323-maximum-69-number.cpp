class Solution {
public:
    int maximum69Number (int num) {
        int ans=0;

        vector<int> temp;
        while(num>0){
            temp.push_back(num%10);
            num=num/10;
        }
        reverse(temp.begin(), temp.end());
        for(int i=0; i<temp.size();i++){
            if(temp[i]==6) {
                temp[i]=9;
                break;
        }
        }
        for(int i=0; i<temp.size(); i++){
            ans= ans*10+temp[i];
        }
        return ans;
    }
};