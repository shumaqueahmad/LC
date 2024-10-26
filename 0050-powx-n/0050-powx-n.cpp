class Solution {
public:
    double calc(double x, long long n){
        if(n==0)
        return 1;

        double temp= myPow(x,n/2);
        temp*=temp;
        if(n%2==1){
            temp*=x;
        }
        return temp;
    }
    double myPow(double x, int n) {
        if (x == 0) return 0;

        long long exp = n;  // Convert n to long long to handle INT_MIN case
        if (exp < 0) {
            x = 1 / x;     // Invert x for negative exponents
            exp = -exp;    // Make exp positive
        }
        
        return calc(x, exp);
    }
};