class Solution {
public:
    int getLucky(string s, int k) {
        vector<int>ans;
        int sum=0;
        for(int i=0; i<s.length(); i++){
            char c=s[i];
            int temp=c-'a'+1;
            sum+=((temp%10)+ (temp/10));
        }
        while(k>1){
            int newsum=0;
            while(sum>0){
                newsum+=sum%10;
                sum/=10;
            }
            sum=newsum;
            k--;
        }
        return sum;
    }
};