class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sum=0;
        int i=0;
        int n=chalk.size();
        long long totalchalk=0;
        for(int i=0 ;i<n; i++)
            totalchalk+=chalk[i];
        
        k=k%totalchalk;
        while(k>=chalk[i]){
            k-=chalk[i];
            i = (i + 1) % n;
        }
        return i;
    }
};