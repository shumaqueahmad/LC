const int mod = 1000000007;

class Solution {
public:
    void func(int ind, long long n, int&  count){

        // base case
        if(ind==n){
            count++;
            return;
        }

        for(int i=ind; i<n; i++){
            if(i%2==0 && i==0){
                for(int i=0; i<4; i++){
                    func(ind+1, n,count);
                }
            }
            else if(i%2==0 && i!=0){
                for(int i=0; i<=4; i++){
                    func(ind+1, n,count);
                }
            }
            else{
                for(int i=0; i<4; i++){
                    func(ind+1, n,count);
                }
            }
        }
    }
    long long expcalc(long long base, long long index){
        
        //base case
        if(index==0)
        return 1;

        long long temp= expcalc(base, index/2);
        temp*=temp;
        temp%=mod;
        if(index%2==1){
            temp*=base;
            temp%=mod;
        }
        return temp;
    }
    int countGoodNumbers(long long n) {
        long long oddind= n/2;
        long long evenind= n-oddind;
        

        //calculate 5^evenind + 4^oddind
        long long a=expcalc(5, evenind);
        long long b= expcalc(4, oddind);    

        return (a*b)%mod;
    }
};